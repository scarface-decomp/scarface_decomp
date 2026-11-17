// bin: xb
// va: 0x002E1D60
// tool: the portal's starter code (no AI)
// sub_002E1D60 (0x002E1D60, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01(int);
};

class Class_002E1D60
{
public:
    void sub_002E1D60();
    char m_pad00[0x18];
    int m_Field18; // +0x18
    char m_pad1C[0x10];
    int m_Field2C; // +0x2C
};

void Class_002E1D60::sub_002E1D60()
{
    int r_ecx, t1, t2;

    r_ecx = (int)this;
    t1 = m_Field18;
    if (m_Field18) {
        r_ecx = t1 + -8;
        if (!r_ecx) goto L_24;
        t2 = *(int*)(r_ecx + 12);
        if (*(int*)(r_ecx + 12) != 2) {
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
