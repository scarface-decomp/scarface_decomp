// bin: xb
// va: 0x002C0F80
// what: Reads part of one signed block of a save file: mounts the unit, loads the block into the shared buffer and copies the bytes out.
// tool: Claude (from SPEC-016)

extern "C" void* __cdecl memcpy(void* to, const void* from, unsigned int count);
#pragma intrinsic(memcpy)

extern "C" char* DAT_004BFE38;          // the transfer buffer: one block, 0x2000 bytes

extern "C" unsigned int __stdcall sub_00233A64(void* file, unsigned int* high);     // GetFileSize
extern "C" unsigned int __stdcall sub_00234B47();                                   // GetLastError

namespace core
{
    // The part of the object in front of the two interfaces (SPEC-016 section 9).
    class DriveFront
    {
    public:
        virtual void Front00();

        char m_pad04[0xCC];
        int m_LastError;            // +0xD0
        int m_FieldD4;              // +0xD4
    };

    // The signed-read interface, at +0xD8.
    class SignedRead
    {
    public:
        virtual int vfunc_00(void* file, const char* name, unsigned int block, unsigned int position,
                             unsigned int count, void* to, int space) = 0;
    };

    // The signed-write interface, at +0xDC.
    class SignedWrite
    {
    public:
        virtual int Write00() = 0;
    };

    class XboxSaveDrive : public DriveFront, public SignedRead, public SignedWrite
    {
    public:
        int sub_002BFE10(unsigned int code);
        bool sub_002BFF10();
        bool sub_002C0030(unsigned int code);
        bool sub_002C0760(void* file, unsigned int block);

        virtual int vfunc_00(void* file, const char* name, unsigned int block, unsigned int position,
                             unsigned int count, void* to, int space);
    };
}

bool core::XboxSaveDrive::sub_002C0030(unsigned int code)
{
    m_LastError = sub_002BFE10(code);
    return m_LastError == 0;
}

int core::XboxSaveDrive::vfunc_00(void* file, const char* name, unsigned int block, unsigned int position,
                                  unsigned int count, void* to, int space)
{
    if (!sub_002BFF10())
    {
        return 0;
    }

    unsigned int size = sub_00233A64(file, 0);
    if (size == 0xFFFFFFFF)
    {
        sub_002C0030(sub_00234B47());
        return 0;
    }

    if (block * 0x2000 < size)
    {
        if (!sub_002C0760(file, block))
        {
            return 0;
        }
        memcpy(to, DAT_004BFE38 + position, count);
    }
    m_LastError = 0;
    return 1;
}
