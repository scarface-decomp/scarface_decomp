// bin: xb
// va: 0x002757F0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::AnimationMemoryBlock::vfunc_03 (0x002757F0, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_0039E22C[];
extern "C" char DAT_003D7534[];
extern "C" void __cdecl sub_00027600(int);

namespace pure3d {

class AnimationMemoryBlock
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual AnimationMemoryBlock* vfunc_03(bool a1);
    char m_pad04[0x14];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

AnimationMemoryBlock* AnimationMemoryBlock::vfunc_03(bool a1)
{
    *(int*)this = (int)DAT_003D7534;
    sub_00027600(m_Field18);
    sub_00027600(m_Field1C);
    *(int*)this = (int)DAT_0039E22C;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}
