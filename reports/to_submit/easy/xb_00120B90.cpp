// bin: xb
// va: 0x00120B90
// tool: the portal's starter code (no AI)
// AIActionPlayAnimAbstract::vfunc_10 (0x00120B90, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_00163D50();
};

class AIActionPlayAnimAbstract
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual int vfunc_10();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

int AIActionPlayAnimAbstract::vfunc_10()
{
    return m_Field08->sub_00163D50() == m_Field0C;
}
