// bin: xb
// va: 0x001972C0
// what: Calls virtual method slot 1 on the embedded member object at +0x2C with (a1, 0).
// tool: Gemini 4 Neon

struct Field2C_001972C0
{
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
    void Call01(int a1, int a2) { vfunc_01(a1, a2); }
};

class Class_001972C0
{
public:
    void sub_001972C0(int a1);
    char m_pad00[0x2C];
    Field2C_001972C0 m_Field2C; // +0x2C
};

void Class_001972C0::sub_001972C0(int a1)
{
    m_Field2C.Call01(a1, 0);
}
