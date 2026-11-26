// bin: xb
// va: 0x002C1180
// what: Starts a search for saves whose names begin with the given text and fills in the first one's directory entry.
// tool: Claude (from SPEC-016 section 14.4)

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
extern "C" bool __cdecl sub_002A93A0(const char* source, int* consumed, unsigned int* character, int c);
extern "C" int __cdecl sub_002A9610(unsigned int character, unsigned short* destination, int room, int a, int* produced, int c);

// 8-bit text to 16-bit text, one character at a time (SPEC-016 section 10.2). File-local: the compiler
// passes its first two arguments in registers.
static int sub_002BFAA0(unsigned short* destination, const char* source, int a, int capacity, int c)
{
    if ((const void*)source == (const void*)destination)
    {
        return -5;
    }
    const char* in = source;
    unsigned short* out = destination;
    int written = 0;
    while (*in != 0)
    {
        unsigned int character;
        int consumed;
        int produced;
        if (!sub_002A93A0(in, &consumed, &character, c))
        {
            return -2;
        }
        int result = sub_002A9610(character, out, capacity - written - 2, a, &produced, c);
        if (result != 0)
        {
            if (result == -1)
            {
                *out = 0;
                return -1;
            }
            return result;
        }
        in += consumed;
        out = (unsigned short*)((char*)out + produced);
        written += produced;
    }
    *out = 0;
    return 0;
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

extern "C" void* __stdcall sub_0030A39A(const char* drive, SaveGameFindData* found);      // XFindFirstSaveGame
extern "C" void __stdcall sub_0030A4EB(void* search);                                      // closes a search
void __cdecl sub_00283A90(unsigned short* destination, const unsigned short* source, int count);  // copies 16-bit text

namespace core
{
    class XboxSaveDrive
    {
    public:
        virtual void vfunc_00();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual void vfunc_08();
        virtual void vfunc_09();
        virtual void vfunc_10();
        virtual void vfunc_11();
        virtual void vfunc_12();
        virtual void vfunc_13();
        virtual void vfunc_14();
        virtual void vfunc_15();
        virtual void vfunc_16();
        virtual void vfunc_17();
        virtual void vfunc_18();
        virtual void vfunc_19();
        virtual int vfunc_20(const char* text, DirectoryEntry* out, unsigned int* index, bool first);
        virtual int vfunc_21(unsigned int* index, DirectoryEntry* out);
        int sub_002BFE10(unsigned int code);
        bool sub_002BFF10();
        bool sub_002BF9C0(const unsigned short* prefix, const unsigned short* text);
        int sub_002C06B0(DirectoryEntry* entry, SaveGameFindData* found, void* search, const unsigned short* prefix);

        char m_pad04[0xCC];
        int m_LastError;            // +0xD0
        char m_padD4[0x26];
        char m_DriveLetter;         // +0xFA
        char m_padFB[0x11];
        SearchEntry m_Pool[4];      // +0x10C
    };
}

// Ends one running search, if it is running.
inline void CloseSearch(SearchEntry* entry)
{
    if (entry->m_Handle != (void*)0xFFFFFFFF)
    {
        sub_0030A4EB(entry->m_Handle);
        entry->m_Handle = (void*)0xFFFFFFFF;
    }
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

int core::XboxSaveDrive::vfunc_20(const char* text, DirectoryEntry* out, unsigned int* index, bool first)
{
    if (!sub_002BFF10())
    {
        return 0;
    }
    char drive[4];
    unsigned short wideText[0x102];
    SaveGameFindData found;
    drive[0] = m_DriveLetter;
    drive[1] = ':';
    drive[2] = '\\';
    drive[3] = 0;
    if (text != 0)
    {
        sub_002BFAA0(wideText, text, 0, 0x202, 0);
    }
    unsigned int slot = 0xFFFFFFFF;
    if (!first && m_Pool[*index].m_Handle != (void*)0xFFFFFFFF)
    {
        slot = *index;
        if (m_Pool[slot].m_Handle != (void*)0xFFFFFFFF)
        {
            sub_0030A4EB(m_Pool[slot].m_Handle);
            m_Pool[slot].m_Handle = (void*)0xFFFFFFFF;
        }
    }
    else
    {
        for (unsigned int i = 0; i < 4; i++)
        {
            if (m_Pool[i].m_Handle == (void*)0xFFFFFFFF)
            {
                slot = i;
                break;
            }
        }
    }
    m_Pool[slot].m_Handle = sub_0030A39A(drive, &found);
    sub_00283A90(m_Pool[slot].m_Text, wideText, 0x202);
    *index = slot;
    int result = sub_002C06B0(out, &found, m_Pool[slot].m_Handle, m_Pool[slot].m_Text);
    if (result == 0)
    {
        return 1;
    }
    if (result == 1)
    {
        m_Pool[slot].m_Handle = (void*)0xFFFFFFFF;
        return 0;
    }
    return vfunc_21(index, out);
}
