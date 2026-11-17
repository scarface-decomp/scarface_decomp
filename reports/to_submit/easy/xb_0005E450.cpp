// bin: xb
// va: 0x0005E450
// tool: the portal's starter code (no AI)
// sub_0005E450 (0x0005E450, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldB8
{
    void sub_0005E2E0();
};

class Class_0005E450
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
    virtual void vfunc_08(int);
    void sub_0005E450();
    void sub_00058660(int);
    char m_pad04[0x7C];
    unsigned char m_Field80; // +0x80
    char m_pad81[0x27];
    float m_FieldA8; // +0xA8
    bool m_FieldAC; // +0xAC
    char m_padAD[0xB];
    FieldB8* m_FieldB8; // +0xB8
    FieldB8* m_FieldBC; // +0xBC
};

void Class_0005E450::sub_0005E450()
{
    vfunc_08(1);
    sub_00058660(0);
    m_FieldA8 = 0.0f;
    m_FieldAC = false;
    m_FieldB8->sub_0005E2E0();
    if (m_FieldBC) {
        m_FieldBC->sub_0005E2E0();
    }
    m_Field80 &= 191;
}
