// bin: xb
// va: 0x0028C140
// tool: the portal's starter code (no AI)
// sub_0028C140 (0x0028C140, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

class Class_0028C140
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int, int);
    void sub_0028C140(bool a1);
    char m_pad04[0xC];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    char m_pad18[0xB5];
    unsigned char m_FieldCD; // +0xCD
};

void Class_0028C140::sub_0028C140(bool a1)
{
    int t1;

    if (a1 != m_FieldCD) {
        t1 = m_Field10;
        m_FieldCD = a1;
        vfunc_07(t1, m_Field14);
    }
}
