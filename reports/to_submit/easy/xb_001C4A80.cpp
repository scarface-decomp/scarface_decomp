// bin: xb
// va: 0x001C4A80
// tool: the portal's starter code (no AI)
// sub_001C4A80 (0x001C4A80, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001C4A80
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int);
    virtual void vfunc_03();
    virtual void vfunc_04();
    void sub_001C4A80(bool a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    char m_pad10[0x8];
    float m_Field18; // +0x18
    bool m_Field1C; // +0x1C
};

void Class_001C4A80::sub_001C4A80(bool a1)
{
    int t1;

    t1 = m_Field0C;
    m_Field18 = 0.0f;
    m_Field1C = false;
    m_Field08 = t1;
    vfunc_04();
    if (a1) {
        vfunc_02(0);
    }
}
