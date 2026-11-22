// bin: proto
// va: 0x0003C010
// what: 
// tool: the portal's starter code (no AI)

// sub_0003C010 (Proto 0x0003C010, 62 bytes)
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

class Class_0003C010
{
public:
    void sub_0003C010(int a1);
    char m_pad00[0x10];
    Field10* m_Field10; // +0x10
    char m_pad14[0x1];
    bool m_Field15; // +0x15
};

void Class_0003C010::sub_0003C010(int a1)
{
    int r_edi;
    Field10* t3;

    if (m_Field10) {
        if (!m_Field15) goto L_1C;
        m_Field10->sub_0003BE90((int)this);
        m_Field15 = false;
    }
L_1C:
    r_edi = a1;
    if (a1) {
        ((Object*)r_edi)->vfunc_00();
    }
    t3 = m_Field10;
    if (m_Field10) {
        ((Object*)(int)t3)->vfunc_01();
    }
    m_Field10 = (Field10*)r_edi;
}
