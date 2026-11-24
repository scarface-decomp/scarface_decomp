// bin: xb
// va: 0x00120A00
// what: Calls sub_001655C0 on m_Field08 and calls sub_000F2770(1, 0) on the returned object.
// tool: Gemini 4 Neon

struct ResultObj_00120A00
{
    void sub_000F2770(int a1, int a2);
};

struct Field08_00120A00
{
    ResultObj_00120A00* sub_001655C0();
};

class AIActionMoveTowards
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
    char m_pad04[0x4];
    Field08_00120A00* m_Field08; // +0x08
};

void AIActionMoveTowards::vfunc_07()
{
    m_Field08->sub_001655C0()->sub_000F2770(1, 0);
}
