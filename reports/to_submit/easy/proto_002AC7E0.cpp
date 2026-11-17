// bin: proto
// va: 0x002AC7E0
// tool: the portal's starter code (no AI)
// sub_002AC7E0 (0x002AC7E0, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01(int);
};

class Class_002AC7E0
{
public:
    void sub_002AC7E0();
    char m_pad00[0x18];
    int m_Field18; // +0x18
    char m_pad1C[0x10];
    int m_Field2C; // +0x2C
};

void Class_002AC7E0::sub_002AC7E0()
{
    int r_ecx, t1, t2;

    r_ecx = (int)this;
    t1 = m_Field18;
    if (m_Field18) {
        r_ecx = t1 + -12;
        if (!r_ecx) goto L_24;
        t2 = *(int*)(r_ecx + 8);
        if (*(int*)(r_ecx + 8) != 2) {
            if (t2 != 4) goto L_24;
        }
        ((Object*)r_ecx)->vfunc_01((int)this);
    }
L_24:
    r_ecx = m_Field2C;
    if (r_ecx != 3) {
        m_Field2C = 3;
    }
}
