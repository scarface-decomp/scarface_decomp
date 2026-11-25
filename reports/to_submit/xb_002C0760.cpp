// bin: xb
// va: 0x002C0760
// what: Loads one block of a save file into the shared buffer (writing back the block that was there first) and checks the block's 20-byte signature.
// tool: Claude (from SPEC-016)

extern "C" int __cdecl memcmp(const void* a, const void* b, unsigned int count);
#pragma intrinsic(memcmp)

// A block's signature: 20 bytes (SPEC-016 section 4).
struct Signature
{
    unsigned int m_Words[5];
};

extern "C" char* DAT_004BFE38;          // the transfer buffer: one block, 0x2000 bytes
extern "C" void* DAT_004BFE3C;          // the file whose block is in the buffer
extern "C" unsigned int DAT_004BFE40;   // which block of that file
extern "C" int DAT_004BFE44;            // 0 = nothing valid, 1 = valid and unchanged, 2 = changed and not yet written

extern "C" unsigned int __stdcall sub_00233A64(void* file, unsigned int* high);                                    // GetFileSize
extern "C" unsigned int __stdcall sub_0023383D(void* file, int distance, int* high, unsigned int from);            // SetFilePointer
extern "C" int __stdcall sub_002335F6(void* file, void* data, unsigned int count, unsigned int* done, void* overlapped);         // ReadFile
extern "C" unsigned int __stdcall sub_00234B47();                                                                  // GetLastError
bool __cdecl sub_002BF7A0(unsigned int size, Signature* signature);     // the signature of the cached block

class XboxSaveDrive
{
public:
    int sub_002BFE10(unsigned int code);
    bool sub_002C0030(unsigned int code);
    bool sub_002C0100();
    bool sub_002C0760(void* file, unsigned int block);

    char m_pad00[0xD0];
    int m_LastError;            // +0xD0
};

bool XboxSaveDrive::sub_002C0030(unsigned int code)
{
    m_LastError = sub_002BFE10(code);
    return m_LastError == 0;
}

bool XboxSaveDrive::sub_002C0760(void* file, unsigned int block)
{
    if (DAT_004BFE44 != 0 && DAT_004BFE3C == file && DAT_004BFE40 == block)
    {
        return true;
    }

    unsigned int size = sub_00233A64(file, 0);
    if (size == 0xFFFFFFFF)
    {
        sub_002C0030(sub_00234B47());
        return false;
    }

    if (!sub_002C0100())
    {
        return false;
    }
    DAT_004BFE44 = 0;

    unsigned int start = block * 0x2000;
    unsigned int end = start + 0x2000;
    if (end >= size)
    {
        end = size;
    }
    unsigned int count = end - start;
    end -= 20;

    unsigned int read;
    if (sub_0023383D(file, start, 0, 0) != start
        || !sub_002335F6(file, DAT_004BFE38, count, &read, 0))
    {
        sub_002C0030(sub_00234B47());
        return false;
    }

    Signature stored = *(Signature*)(DAT_004BFE38 + (end - start));
    DAT_004BFE3C = file;
    DAT_004BFE40 = block;

    Signature computed;
    if (!sub_002BF7A0(size, &computed))
    {
        sub_002C0030(sub_00234B47());
        return false;
    }

    if (memcmp(&computed, &stored, sizeof(Signature)) != 0)
    {
        m_LastError = 0xC;
        return false;
    }

    DAT_004BFE44 = 1;
    return true;
}
