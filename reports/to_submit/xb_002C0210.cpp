// bin: xb
// va: 0x002C0210
// what: Writes out a new save file's blocks, zero-filled, each with its signature; the first block can hold the file's size. Leaves the last block in the shared buffer.
// tool: Claude (from SPEC-016)

extern "C" void* __cdecl memset(void* to, int value, unsigned int count);
#pragma intrinsic(memset)

// A block's signature: 20 bytes (SPEC-016 section 4).
struct Signature
{
    unsigned int m_Words[5];
};

const unsigned int BLOCK = 0x2000;
const unsigned int BLOCK_DATA = BLOCK - sizeof(Signature);

extern "C" char* DAT_004BFE38;          // the transfer buffer: one block, 0x2000 bytes
extern "C" void* DAT_004BFE3C;          // the file whose block is in the buffer
extern "C" unsigned int DAT_004BFE40;   // which block of that file
extern "C" int DAT_004BFE44;            // 0 = nothing valid, 1 = valid and unchanged, 2 = changed and not yet written

extern "C" unsigned int __stdcall sub_0023383D(void* file, int distance, int* high, unsigned int from);            // SetFilePointer
extern "C" int __stdcall sub_002336E3(void* file, const void* data, unsigned int count, unsigned int* done, void* overlapped);   // WriteFile
extern "C" unsigned int __stdcall sub_00234B47();                                                                  // GetLastError
extern "C" void* __stdcall sub_0023949C(unsigned int flags);                                                       // XCalculateSignatureBegin
extern "C" unsigned int __stdcall sub_002394B0(void* handle, const void* data, unsigned int size);                 // XCalculateSignatureUpdate
extern "C" unsigned int __stdcall sub_002394FE(void* handle, Signature* signature);                                // XCalculateSignatureEnd

// The signature of a run of bytes.
bool __cdecl sub_002BF760(const void* data, unsigned int size, Signature* signature)
{
    void* handle = sub_0023949C(0);
    if (handle == (void*)0xFFFFFFFF)
    {
        return false;
    }
    sub_002394B0(handle, data, size);
    sub_002394FE(handle, signature);
    return true;
}

namespace core
{
    class XboxSaveDrive
    {
    public:
        int sub_002BFE10(unsigned int code);
        bool sub_002C0030(unsigned int code);
        bool sub_002C0100();
        bool sub_002C0210(void* file, unsigned int size, bool validHeader);

        char m_pad00[0xD0];
        int m_LastError;            // +0xD0
    };
}

bool core::XboxSaveDrive::sub_002C0030(unsigned int code)
{
    m_LastError = sub_002BFE10(code);
    return m_LastError == 0;
}

bool core::XboxSaveDrive::sub_002C0210(void* file, unsigned int size, bool validHeader)
{
    if (!sub_002C0100())
    {
        return false;
    }
    DAT_004BFE44 = 0;
    memset(DAT_004BFE38, 0, BLOCK);

    unsigned int remaining = size;
    if (validHeader)
    {
        *(unsigned int*)DAT_004BFE38 = size;
    }

    Signature signature;
    if (size > BLOCK)
    {
        if (!sub_002BF760(DAT_004BFE38, BLOCK_DATA, &signature))
        {
            sub_002C0030(sub_00234B47());
            return false;
        }
        *(Signature*)(DAT_004BFE38 + BLOCK_DATA) = signature;
    }

    if (sub_0023383D(file, 0, 0, 0) != 0)
    {
        sub_002C0030(sub_00234B47());
        return false;
    }

    unsigned int written;
    unsigned int block = 0;
    while (remaining > BLOCK)
    {
        if (!sub_002336E3(file, DAT_004BFE38, BLOCK, &written, 0))
        {
            sub_002C0030(sub_00234B47());
            return false;
        }
        if (block == 0 && validHeader)
        {
            // only the first block holds the size: the ones after it start with zero
            *(unsigned int*)DAT_004BFE38 = 0;
            if (!sub_002BF760(DAT_004BFE38, BLOCK_DATA, &signature))
            {
                sub_002C0030(sub_00234B47());
                return false;
            }
            *(Signature*)(DAT_004BFE38 + BLOCK_DATA) = signature;
        }
        remaining -= BLOCK;
        block++;
    }

    if (remaining > 0)
    {
        *(unsigned int*)DAT_004BFE38 = 0;
        if (!sub_002BF760(DAT_004BFE38, remaining - sizeof(Signature), &signature))
        {
            sub_002C0030(sub_00234B47());
            return false;
        }
        *(Signature*)(DAT_004BFE38 + remaining - sizeof(Signature)) = signature;
        if (!sub_002336E3(file, DAT_004BFE38, remaining, &written, 0))
        {
            sub_002C0030(sub_00234B47());
            return false;
        }
        block++;
    }

    DAT_004BFE3C = file;
    DAT_004BFE40 = block - 1;
    DAT_004BFE44 = 1;
    return true;
}
