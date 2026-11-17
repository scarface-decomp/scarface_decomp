// bin: xb
// va: 0x000EFCF0
// tool: the portal's starter code (no AI)
// GlanceAtOvertakingPed::vfunc_07 (0x000EFCF0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_000CA1C0();
};

class GlanceAtOvertakingPed
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
};

int GlanceAtOvertakingPed::vfunc_07()
{
    return !((Object*)(int)this + 20)->sub_000CA1C0();
}
