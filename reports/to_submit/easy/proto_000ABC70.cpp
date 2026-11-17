// bin: proto
// va: 0x000ABC70
// tool: the portal's starter code (no AI)
// sub_000ABC70 (0x000ABC70, 89 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    int sub_00097830(int);
};

struct Object
{
    virtual void vfunc_00();
};

extern "C" float DAT_003845A4;

class Class_000ABC70
{
public:
    void sub_000ABC70();
    float m_Field00; // +0x00
    int m_Field04; // +0x04
    bool m_Field08; // +0x08
    char m_pad09[0x3];
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    Field14* m_Field14; // +0x14
    char m_pad18[0x4];
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
};

void Class_000ABC70::sub_000ABC70()
{
    int t2, t3, t4, t6;

    m_Field00 = DAT_003845A4;
    if (!m_Field14) goto L_46;
    t2 = m_Field04;
    t3 = m_Field14->sub_00097830(0x42C80000);
    m_Field04 = t3;
    if (t3 >= 0) {
        if (t3 == t2) goto L_45;
        t4 = m_Field1C;
        if (m_Field1C) {
            ((Object*)t4)->vfunc_00();
        }
        t6 = m_Field20;
        if (!m_Field20) goto L_45;
        ((Object*)t6)->vfunc_00();
    }
L_45:
L_46:
    m_Field08 = false;
    m_Field0C = 0.0f;
    m_Field10 = 0.0f;
}
