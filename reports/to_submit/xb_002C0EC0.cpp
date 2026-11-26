// bin: xb
// va: 0x002C0EC0
// what: Commits a save file: writes the cached block back and, for a file whose first block still needs it, stores the file's size in block 0.
// tool: Claude (from SPEC-016)

extern "C" char* DAT_004BFE38;          // the transfer buffer: one block, 0x2000 bytes
extern "C" void* DAT_004BFE3C;          // the file whose block is in the buffer
extern "C" int DAT_004BFE44;            // 0 = nothing valid, 1 = valid and unchanged, 2 = changed and not yet written

extern "C" unsigned int __stdcall sub_00233A64(void* file, unsigned int* high);     // GetFileSize
extern "C" unsigned int __stdcall sub_00234B47();                                   // GetLastError

namespace core
{
    class XboxSaveDrive
    {
    public:
        int sub_002BFE10(unsigned int code);
        bool sub_002BFF10();
        bool sub_002C0030(unsigned int code);
        bool sub_002C0100();
        bool sub_002C0760(void* file, unsigned int block);
        int vfunc_13(void* file, const char* name);

        char m_pad00[0xD0];
        int m_LastError;            // +0xD0
        char m_padD4[0x28];
        void* m_NeedSize[4];        // +0xFC: files whose first block still needs its size written
    };
}

bool core::XboxSaveDrive::sub_002C0030(unsigned int code)
{
    m_LastError = sub_002BFE10(code);
    return m_LastError == 0;
}

int core::XboxSaveDrive::vfunc_13(void* file, const char* name)
{
    if (!sub_002BFF10())
    {
        return 0;
    }
    if (!sub_002C0100())
    {
        return 0;
    }
    bool found = false;
    unsigned int i;
    for (i = 0; i < 4; i++)
    {
        if (DAT_004BFE3C == m_NeedSize[i])
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        if (!sub_002C0760(file, 0))
        {
            return 0;
        }
        unsigned int size = sub_00233A64(file, 0);
        if (size == 0xFFFFFFFF)
        {
            sub_002C0030(sub_00234B47());
            return 0;
        }
        *(unsigned int*)DAT_004BFE38 = size;
        DAT_004BFE44 = 2;
        if (!sub_002C0100())
        {
            return 0;
        }
        m_NeedSize[i] = (void*)0xFFFFFFFF;
    }
    m_LastError = 0;
    return 1;
}
