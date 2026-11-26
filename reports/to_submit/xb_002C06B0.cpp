// bin: xb
// va: 0x002C06B0
// what: Turns one step of a save-game search into a directory entry: end of list, an error, a skip if the name lacks the wanted start, or the name as 8-bit text.
// tool: Claude (from the bytes; SPEC-016 sections 10.1 and 10.3)

extern "C" unsigned int __stdcall sub_00234B47();       // GetLastError

extern "C" bool __cdecl sub_002A95A0(const unsigned short* source, int* consumed, unsigned int* character, int c);
extern "C" int __cdecl sub_002A9430(unsigned int character, char* destination, int room, int a, int* produced, int c);

// 16-bit text to 8-bit text, one character at a time (SPEC-016 section 10.1). File-local: the compiler
// passes its first two arguments in ECX and EAX.
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

// What the system's save-game search fills in; only the save's name is used here.
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

namespace core
{
    class XboxSaveDrive
    {
    public:
        int sub_002BFE10(unsigned int code);
        bool sub_002BF9C0(const unsigned short* prefix, const unsigned short* text);
        int sub_002C06B0(DirectoryEntry* entry, SaveGameFindData* found, void* search, const unsigned short* prefix);

        char m_pad00[0xD0];
        int m_LastError;            // +0xD0
    };
}

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
            return 2;       // not one of ours: the caller goes on to the next
        }
    }
    m_LastError = 0;
    return 0;
}
