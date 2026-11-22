// bin: proto
// va: 0x001062D0
// what: 
// tool: the portal's starter code (no AI)

// AIConditionIsInFightTreePhysicalMode::vfunc_04 (Proto 0x001062D0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class AIConditionIsInFightTreePhysicalMode
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

int AIConditionIsInFightTreePhysicalMode::vfunc_04()
{
    return *(int*)(m_Field08 + 992) == m_Field0C;
}
