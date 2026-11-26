// bin: xb
// va: 0x002BFAA0
// what: Converts 8-bit text to 16-bit text one character at a time, stopping with an error when the destination is full.
// tool: Claude (from SPEC-016)

extern "C" bool __cdecl sub_002A93A0(const char* source, int* consumed, unsigned int* character, int c);
extern "C" int __cdecl sub_002A9610(unsigned int character, unsigned short* destination, int room, int a, int* produced, int c);
extern "C" unsigned int __stdcall sub_0030A2CA(const char* drive, const unsigned short* name);     // XDeleteSaveGame

// 8-bit text to 16-bit text, one character at a time (SPEC-016 section 10.2). File-local: the compiler
// passes its first two arguments in ECX and EAX.
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

namespace core
{
    class XboxSaveDrive
    {
    public:
        int sub_002BFE10(unsigned int code);
        bool sub_002BFF10();
        int vfunc_19(const char* name);

        char m_pad00[0xD0];
        int m_LastError;            // +0xD0
        char m_padD4[0x26];
        char m_DriveLetter;         // +0xFA
    };
}

int core::XboxSaveDrive::vfunc_19(const char* name)
{
    if (!sub_002BFF10())
    {
        return 0;
    }

    char drive[4];
    unsigned short wideName[0x102];
    drive[0] = m_DriveLetter;
    drive[1] = ':';
    drive[2] = '\\';
    drive[3] = 0;
    if (name != 0)
    {
        sub_002BFAA0(wideName, name, 0, 0x202, 0);
    }

    unsigned int code = sub_0030A2CA(drive, wideName);
    if (code != 0)
    {
        m_LastError = sub_002BFE10(code);
        return 0;
    }
    m_LastError = 0;
    return 1;
}
