// bin: xb
// va: 0x002BF8A0
// what: Gives the space a new save of a given size needs on the memory unit, rounded to 0x4000 with room for the directory.
// tool: Claude (from SPEC-016)

const unsigned int BLOCK_DATA = 0x2000 - 20;     // a block less its signature

extern "C" unsigned int __cdecl sub_00250E80(unsigned int value, unsigned int step);

inline unsigned int SizeOnDisk(unsigned int size)
{
    return size + 4 + 20 * ((size + 4 + BLOCK_DATA - 1) / BLOCK_DATA);
}

struct SaveInfo
{
    int m_Field0; // +0x0
};

namespace core
{
    class XboxSaveDrive
    {
    public:
        unsigned int vfunc_06(SaveInfo* info, unsigned int size);
    };
}

unsigned int core::XboxSaveDrive::vfunc_06(SaveInfo* info, unsigned int size)
{
    unsigned int needed = sub_00250E80(SizeOnDisk(size), 0x4000) + 0x8000;
    if (info->m_Field0 != 0)
    {
        needed += 0x4000;
    }
    return needed;
}
