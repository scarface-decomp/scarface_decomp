// bin: proto
// va: 0x0003BEF0
// tool: the portal's starter code (no AI)
// sub_0003BEF0 (0x0003BEF0, 79 bytes)
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

extern "C" char DAT_0037D85C[];
extern "C" char DAT_0037F6BC[];

class Class_0003BEF0
{
public:
    void sub_0003BEF0();
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    Field10* m_Field10; // +0x10
    char m_pad14[0x1];
    bool m_Field15; // +0x15
};

void Class_0003BEF0::sub_0003BEF0()
{
    int t2;
    Field10* t4;

    m_Field00 = (int)DAT_0037F6BC;
    if (m_Field10) {
        if (!m_Field15) goto L_21;
        m_Field10->sub_0003BE90((int)this);
        m_Field15 = false;
    }
L_21:
    t2 = m_Field0C;
    if (m_Field0C) {
        ((Object*)t2)->vfunc_01();
        m_Field0C = 0;
    }
    t4 = m_Field10;
    if (m_Field10) {
        ((Object*)(int)t4)->vfunc_01();
        m_Field10 = 0;
    }
    m_Field00 = (int)DAT_0037D85C;
}
