// bin: xb
// va: 0x0025EBB0
// what: Deleting destructor: runs the destructor, then frees the object when asked to.
// tool: Claude Opus 5.5 (byte copy of the matched 0x0023B160 with its own addresses, examiner A6: pure3d::SpriteParticleEmitter::OverLifeAttributes::vfunc_03)

extern "C" void __cdecl sub_00027600(void* p);

class Class_0025EBB0
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Class_0025EBB0* sub_0025EBB0(unsigned int flags);
    void sub_0025DB70();
};

#pragma optimize("y", off)
Class_0025EBB0* Class_0025EBB0::sub_0025EBB0(unsigned int flags)
{
    sub_0025DB70();
    if (flags & 1)
        sub_00027600(this);
    return this;
}
#pragma optimize("", on)
