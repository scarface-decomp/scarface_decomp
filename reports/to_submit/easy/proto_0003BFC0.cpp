// bin: proto
// va: 0x0003BFC0
// tool: the portal's starter code (no AI)
// sub_0003BFC0 (0x0003BFC0, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_0003BE90(int);
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_0003BFC0
{
public:
    void sub_0003BFC0(int a1, bool a2);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    Field10* m_Field10; // +0x10
    char m_pad14[0x1];
    bool m_Field15; // +0x15
    bool m_Field16; // +0x16
};

void Class_0003BFC0::sub_0003BFC0(int a1, bool a2)
{
    int r_edi, t3;

    if (m_Field10) {
        if (!m_Field15) goto L_1C;
        m_Field10->sub_0003BE90((int)this);
        m_Field15 = false;
    }
L_1C:
    r_edi = a1;
    m_Field16 = a2;
    if (a1) {
        ((Object*)r_edi)->vfunc_00();
    }
    t3 = m_Field0C;
    if (m_Field0C) {
        ((Object*)t3)->vfunc_01();
    }
    m_Field0C = r_edi;
}
