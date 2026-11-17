// bin: xb
// va: 0x00271A10
// tool: the portal's starter code (no AI)
// pure3d::ParticleAllocatorTemplate<pure3d::SpriteParticle>::vfunc_03 (0x00271A10, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00271A40(void);

namespace pure3d { class SpriteParticle; }

namespace pure3d { 
template <class T0> class ParticleAllocatorTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ParticleAllocatorTemplate<pure3d::SpriteParticle>* vfunc_03(int a1);
};
}

template <> pure3d::ParticleAllocatorTemplate<pure3d::SpriteParticle>* pure3d::ParticleAllocatorTemplate<pure3d::SpriteParticle>::vfunc_03(int a1)
{
    sub_00271A40();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}
