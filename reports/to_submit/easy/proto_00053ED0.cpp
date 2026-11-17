// bin: proto
// va: 0x00053ED0
// tool: the portal's starter code (no AI)
// sub_00053ED0 (0x00053ED0, 79 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldAC
{
    void sub_00053A30(int);
};

struct Object
{
    void sub_00053A30(int);
};

class Class_00053ED0
{
public:
    void sub_00053ED0(int a1);
    char m_pad00[0xA0];
    int m_FieldA0; // +0xA0
    char m_padA4[0x8];
    FieldAC* m_FieldAC; // +0xAC
    int m_FieldB0; // +0xB0
};

void Class_00053ED0::sub_00053ED0(int a1)
{
    int t1, t4;

    t1 = m_FieldA0;
    if (m_FieldA0 <= 1) goto L_4B;
    if (a1 >= 0) {
        if (a1 >= t1) goto L_4A;
        m_FieldAC->sub_00053A30(*(int*)((int)this + (a1 * 4) + 128));
        t4 = m_FieldB0;
        if (!m_FieldB0) goto L_4A;
        a1 = *(int*)((int)this + (a1 * 4) + 128);
        ((Object*)t4)->sub_00053A30(a1);
        return;
    }
L_4A:
L_4B:
    ;
}
