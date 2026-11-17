// bin: xb
// va: 0x00281C00
// tool: the portal's starter code (no AI)
// sub_00281C00 (0x00281C00, 89 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_00281C00
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
    virtual void vfunc_08(int, int);
    void sub_00281C00(int a1);
    void sub_00281400();
    void sub_00281670();
    char m_pad04[0x38];
    int m_Field3C; // +0x3C
    int m_Field40; // +0x40
    char m_pad44[0x40];
    int m_Field84; // +0x84
    unsigned char m_Field88; // +0x88
};

void Class_00281C00::sub_00281C00(int a1)
{
    int t1;

    if (m_Field3C == -1) {
        t1 = m_Field84;
        if (!m_Field84) goto L_25;
        ((Object*)t1)->vfunc_01();
        m_Field84 = 0;
    }
L_25:
    m_Field3C = a1;
    m_Field40 = 0;
    sub_00281400();
    vfunc_08(0, 0);
    if (m_Field88 == 1) {
        sub_00281670();
    }
}
