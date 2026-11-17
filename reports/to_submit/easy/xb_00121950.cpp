// bin: xb
// va: 0x00121950
// tool: the portal's starter code (no AI)
// AIConditionIsInFightTreePhysicalMode::vfunc_04 (0x00121950, 18 bytes)
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
    return *(int*)(m_Field08 + 1052) == m_Field0C;
}
