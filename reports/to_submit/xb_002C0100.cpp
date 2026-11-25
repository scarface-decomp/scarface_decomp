// bin: xb
// va: 0x002C0100
// what: Writes the cached save-file block back to its file if it was changed, with its 20-byte signature placed at the end of the block.
// tool: Claude (from SPEC-016)

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
extern "C" int __stdcall sub_002336E3(void* file, const void* data, unsigned int count, unsigned int* done, void* overlapped);  // WriteFile
extern "C" unsigned int __stdcall sub_00234B47();                                                                  // GetLastError
bool __cdecl sub_002BF7A0(unsigned int size, Signature* signature);     // the signature of the cached block

class XboxSaveDrive
{
public:
    int sub_002BFE10(unsigned int code);
    bool sub_002C0100();

    bool sub_002C0030(unsigned int code)
    {
        m_LastError = sub_002BFE10(code);
        return m_LastError == 0;
    }

    char m_pad00[0xD0];
    int m_LastError;            // +0xD0
};

bool XboxSaveDrive::sub_002C0100()
{
    if (DAT_004BFE44 != 2)
    {
        return true;
    }

    unsigned int size = sub_00233A64(DAT_004BFE3C, 0);
    if (size == 0xFFFFFFFF)
    {
        sub_002C0030(sub_00234B47());
        return false;
    }

    Signature signature;
    if (!sub_002BF7A0(size, &signature))
    {
        sub_002C0030(sub_00234B47());
        return false;
    }

    unsigned int start = DAT_004BFE40 * 0x2000;
    unsigned int end = start + 0x2000;
    if (end >= size)
    {
        end = size;
    }
    *(Signature*)(DAT_004BFE38 + (end - 20 - start)) = signature;

    unsigned int written;
    if (sub_0023383D(DAT_004BFE3C, start, 0, 0) != start
        || !sub_002336E3(DAT_004BFE3C, DAT_004BFE38, end - start, &written, 0))
    {
        sub_002C0030(sub_00234B47());
        return false;
    }

    DAT_004BFE44 = 1;
    return true;
}
