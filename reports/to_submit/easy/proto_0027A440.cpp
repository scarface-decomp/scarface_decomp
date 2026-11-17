// bin: proto
// va: 0x0027A440
// tool: the portal's starter code (no AI)
// pure3d::xboxOceanReflection::vfunc_01 (0x0027A440, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00315720(int, int);

namespace pure3d {

class xboxOceanReflection
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    int m_Field04; // +0x04
    char m_pad08[0x4];
    int m_Field0C; // +0x0C
};

void xboxOceanReflection::vfunc_01(int a1)
{
    if (m_Field04) {
        sub_00315720(a1, m_Field0C);
    }
}

}
