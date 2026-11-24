// bin: xb
// va: 0x00292CF0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::BoneMatrixList::vfunc_03 (0x00292CF0, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_0039E22C[];
extern "C" char DAT_003D8D3C[];
extern "C" void __cdecl sub_00027600(int);

namespace pure3d {

class BoneMatrixList
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual BoneMatrixList* vfunc_03(bool a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

BoneMatrixList* BoneMatrixList::vfunc_03(bool a1)
{
    *(int*)this = (int)DAT_003D8D3C;
    sub_00027600(m_Field0C);
    sub_00027600(m_Field10);
    sub_00027600(m_Field14);
    sub_00027600(m_Field18);
    *(int*)this = (int)DAT_0039E22C;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}
