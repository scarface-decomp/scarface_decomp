// bin: xb
// va: 0x002580B0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::ShadowSkinTopology::vfunc_03 (0x002580B0, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_0039E22C[];
extern "C" char DAT_003D5924[];
extern "C" void __cdecl sub_00027600(int);

namespace pure3d {

class ShadowSkinTopology
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ShadowSkinTopology* vfunc_03(bool a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

ShadowSkinTopology* ShadowSkinTopology::vfunc_03(bool a1)
{
    *(int*)this = (int)DAT_003D5924;
    sub_00027600(m_Field08);
    sub_00027600(m_Field0C);
    sub_00027600(m_Field10);
    *(int*)this = (int)DAT_0039E22C;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}
