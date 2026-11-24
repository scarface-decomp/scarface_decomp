// bin: xb
// va: 0x000AB050
// what: Calls virtual method slot 3 on the member pointer at +0x2A8 if it is non-null.
// tool: Gemini 4 Neon

struct Field2A8
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
};

class Class_000AB050
{
public:
    void sub_000AB050();
    char m_pad00[0x2A8];
    Field2A8* m_Field2A8; // +0x2A8
};

void Class_000AB050::sub_000AB050()
{
    if (m_Field2A8) {
        m_Field2A8->vfunc_03();
    }
}
