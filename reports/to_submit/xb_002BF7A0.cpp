// bin: xb
// va: 0x002BF7A0
// what: Computes the 20-byte signature of the block in the shared save buffer, leaving out the signature's own place at the end.
// tool: Claude (from SPEC-016)

struct Signature
{
    unsigned int m_Words[5];
};

extern "C" char* DAT_004BFE38;          // the transfer buffer: one block, 0x2000 bytes
extern "C" unsigned int DAT_004BFE40;   // which block of the file is in it

extern "C" void* __stdcall sub_0023949C(unsigned int flags);                                    // XCalculateSignatureBegin
extern "C" unsigned int __stdcall sub_002394B0(void* handle, const void* data, unsigned int size);   // XCalculateSignatureUpdate
extern "C" unsigned int __stdcall sub_002394FE(void* handle, void* signature);                  // XCalculateSignatureEnd

inline bool Sign(const void* data, unsigned int size, Signature* signature)
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

bool __cdecl sub_002BF7A0(unsigned int fileSize, Signature* signature)
{
    unsigned int start = DAT_004BFE40 * 0x2000;
    unsigned int end = start + 0x2000;
    if (end >= fileSize)
    {
        end = fileSize;
    }
    return Sign(DAT_004BFE38, end - start - 20, signature);
}
