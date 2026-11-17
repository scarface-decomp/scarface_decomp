// bin: proto
// va: 0x000AD630
// tool: the portal's starter code (no AI)
// sub_000AD630 (0x000AD630, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_002BA820();
};

struct Object
{
    void sub_00012020(int);
};

class Class_000AD630
{
public:
    void sub_000AD630();
    void sub_000ABF30(int);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    Field08* m_Field08; // +0x08
    bool m_Field0C; // +0x0C
    char m_pad0D[0x27];
    bool m_Field34; // +0x34
};

void Class_000AD630::sub_000AD630()
{
    int t2, t3;

    if (m_Field0C) {
        if (m_Field34) goto L_45;
        if (*(unsigned char*)m_Field08 & 1) {
            m_Field08->sub_002BA820();
        }
        t2 = m_Field00;
        if (!m_Field00) goto L_45;
        if (!m_Field04) goto L_45;
        t3 = *(int*)t2;
        m_Field34 = true;
        sub_000ABF30(0);
        ((Object*)t3)->sub_00012020(1);
    }
L_45:
    ;
}
