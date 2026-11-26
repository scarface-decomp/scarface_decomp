// bin: xb
// va: 0x002CC160
// what: Reads bytes from a signed save file block by block: the rest of the first block, whole blocks, then what is left; reports the count read.
// tool: Claude (from the bytes; the caller is in SPEC-016 section 10.8)

extern "C" unsigned int __cdecl sub_00250E60(unsigned int value, unsigned int step);   // rounds value down to a multiple of step

namespace core
{
    // The signed-read interface (SPEC-016 section 9): the drive supplies the three virtual functions.
    class SignedRead
    {
    public:
        virtual int vfunc_00(void* file, const char* name, unsigned int block, unsigned int position,
                             unsigned int count, void* to, int space) = 0;
        virtual unsigned int vfunc_01() = 0;            // bytes of data in one block
        virtual unsigned int vfunc_02(void* file) = 0;  // bytes in front of the data in the file

        int sub_002CC160(void* drive, void* file, const char* name, unsigned int position, void* to,
                         unsigned int count, unsigned int* done, int space);
    };
}

int core::SignedRead::sub_002CC160(void* drive, void* file, const char* name, unsigned int position, void* to,
                                   unsigned int count, unsigned int* done, int space)
{
    unsigned int blockData = vfunc_01();
    position += vfunc_02(file);
    unsigned int block = position / blockData;
    unsigned int offset = position - sub_00250E60(position, blockData);
    unsigned int part = blockData - offset;
    if (part >= count)
    {
        part = count;
    }

    int result = vfunc_00(file, name, block, offset, part, to, space);
    if (result != 1)
    {
        return result;
    }
    unsigned int left = count - part;
    block++;
    char* out = (char*)to + part;

    while (left >= blockData)
    {
        result = vfunc_00(file, name, block, 0, blockData, out, space);
        if (result != 1)
        {
            return result;
        }
        left -= blockData;
        block++;
        out += blockData;
    }
    if (left > 0)
    {
        result = vfunc_00(file, name, block, 0, left, out, space);
        if (result != 1)
        {
            return result;
        }
    }
    *done = count;
    return 1;
}
