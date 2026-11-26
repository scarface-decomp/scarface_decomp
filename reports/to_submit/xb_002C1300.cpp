// bin: xb
// va: 0x002C1300
// what: Finds the next save in a running search and fills in its directory entry; at the end of the list the entry says so.
// tool: Claude (from SPEC-016 section 14.3)

extern "C" unsigned int __stdcall sub_00234B47();       // GetLastError

extern "C" bool __cdecl sub_002A95A0(const unsigned short* source, int* consumed, unsigned int* character, int c);
extern "C" int __cdecl sub_002A9430(unsigned int character, char* destination, int room, int a, int* produced, int c);

// 16-bit text to 8-bit text, one character at a time (SPEC-016 section 10.1). File-local: the compiler
// passes its first two arguments in registers.
static int sub_002BFA00(char* destination, const unsigned short* source, int a, int capacity, int c)
{
    if ((const void*)source == (const void*)destination)
    {
        return -5;
    }
    const unsigned short* in = source;
    char* out = destination;
    int written = 0;
    while (*in != 0)
    {
        unsigned int character;
        int consumed;
        int produced;
        if (!sub_002A95A0(in, &consumed, &character, c))
        {
            return -2;
        }
        int result = sub_002A9430(character, out, capacity - written - 1, a, &produced, c);
        if (result != 0)
        {
            if (result == -1)
            {
                *out = 0;
                return -1;
            }
            return result;
        }
        in = (const unsigned short*)((const char*)in + consumed);
        out += produced;
        written += produced;
    }
    *out = 0;
    return 0;
}

int __cdecl sub_002C0480(char* destination, const unsigned short* source, int a, int capacity, int c)
{
    if (destination == 0)
    {
        return -3;
    }
    if (source == 0)
    {
        return -2;
    }
    return sub_002BFA00(destination, source, a, capacity, c);
}
// What the system's save-game search fills in (0x344 bytes); only the save's name is used here.
struct SaveGameFindData
{
    char m_pad000[0x244];
    unsigned short m_SaveName[0x80];    // +0x244
};

// One directory entry handed back to the caller.
struct DirectoryEntry
{
    int m_Kind;             // +0x0: 2 = no more entries, 3 = a file
    char m_Name[0x101];     // +0x4
};

// One running search: the text the saves' names must start with, and the system's search handle.
struct SearchEntry
{
    unsigned short m_Text[0x102];   // +0x000
    void* m_Handle;                 // +0x204, 0xFFFFFFFF when unused
};

extern "C" int __stdcall sub_0030A4A4(void* search, SaveGameFindData* found);     // XFindNextSaveGame

namespace core
{
    class XboxSaveDrive
    {
    public:
        int sub_002BFE10(unsigned int code);
        bool sub_002BFF10();
        bool sub_002BF9C0(const unsigned short* prefix, const unsigned short* text);
        int sub_002C06B0(DirectoryEntry* entry, SaveGameFindData* found, void* search, const unsigned short* prefix);
        int vfunc_21(unsigned int* index, DirectoryEntry* out);

        char m_pad00[0xD0];
        int m_LastError;            // +0xD0
        char m_padD4[0x38];
        SearchEntry m_Pool[4];      // +0x10C
    };
}

// Turns one step of a search into a directory entry (0x2C06B0): 0 = filled in, 1 = failed, 2 = skip.
int core::XboxSaveDrive::sub_002C06B0(DirectoryEntry* entry, SaveGameFindData* found, void* search,
                                      const unsigned short* prefix)
{
    if (search == (void*)0xFFFFFFFF)
    {
        unsigned int code = sub_00234B47();
        if (code == 18)
        {
            entry->m_Name[0] = 0;
            entry->m_Kind = 2;
        }
        else
        {
            m_LastError = sub_002BFE10(code);
            return 1;
        }
    }
    else
    {
        if (sub_002BF9C0(found->m_SaveName, prefix))
        {
            sub_002C0480(entry->m_Name, found->m_SaveName, 0, 0x101, 0);
            entry->m_Kind = 3;
        }
        else
        {
            return 2;
        }
    }
    m_LastError = 0;
    return 0;
}

int core::XboxSaveDrive::vfunc_21(unsigned int* index, DirectoryEntry* out)
{
    unsigned int slot = *index;
    if (m_Pool[slot].m_Handle == (void*)0xFFFFFFFF)
    {
        m_LastError = 1;
        return 0;
    }
    if (!sub_002BFF10())
    {
        return 0;
    }
    SaveGameFindData found;
    for (;;)
    {
        int result;
        if (sub_0030A4A4(m_Pool[slot].m_Handle, &found))
        {
            result = sub_002C06B0(out, &found, m_Pool[slot].m_Handle, m_Pool[slot].m_Text);
        }
        else
        {
            result = sub_002C06B0(out, &found, (void*)0xFFFFFFFF, m_Pool[slot].m_Text);
        }
        if (result == 0)
        {
            return 1;
        }
        if (result == 1)
        {
            return 0;
        }
        if (result != 2)
        {
            m_LastError = 0;
            return 1;
        }
    }
}
