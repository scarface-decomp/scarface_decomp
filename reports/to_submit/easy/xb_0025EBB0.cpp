// bin: xb
// va: 0x0025EBB0
// tool: the portal's starter code (no AI)
// pure3d::SpriteParticleEmitter::OverLifeAttributes::vfunc_03 (0x0025EBB0, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0025DB70(void);

namespace pure3d { namespace SpriteParticleEmitter {

class OverLifeAttributes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual OverLifeAttributes* vfunc_03(int a1);
};

OverLifeAttributes* OverLifeAttributes::vfunc_03(int a1)
{
    sub_0025DB70();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

} }
