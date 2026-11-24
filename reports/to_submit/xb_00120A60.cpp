// bin: xb
// va: 0x00120A60
// what: Calls sub_001655C0 on m_Field08 and passes (&m_Field0C, 1) to sub_000F2860 on the returned object.
// tool: Gemini 4 Neon

struct ResultObj_00120A60
{
    void sub_000F2860(int* targetPtr, int flag);
};

struct Field08_00120A60
{
    ResultObj_00120A60* sub_001655C0();
};

class AIActionAimAt
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    char m_pad04[0x4];
    Field08_00120A60* m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

void AIActionAimAt::vfunc_02()
{
    m_Field08->sub_001655C0()->sub_000F2860(&m_Field0C, 1);
}
