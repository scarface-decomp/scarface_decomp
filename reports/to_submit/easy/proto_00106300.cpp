// bin: proto
// va: 0x00106300
// tool: the portal's starter code (no AI)
// AIConditionNot::vfunc_04 (0x00106300, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual bool vfunc_04();
};

class AIConditionNot
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

int AIConditionNot::vfunc_04()
{
    return !m_Field08->vfunc_04();
}
