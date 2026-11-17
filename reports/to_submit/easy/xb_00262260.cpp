// bin: xb
// va: 0x00262260
// tool: the portal's starter code (no AI)
// sub_00262260 (0x00262260, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
    virtual void vfunc_01();
};

class Class_00262260
{
public:
    void sub_00262260();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    char m_pad08[0x7C];
    int m_Field84; // +0x84
};

void Class_00262260::sub_00262260()
{
    int r_edi, r_esi, t1, t4;

    t1 = m_Field84;
    if (m_Field84) {
        ((Object*)t1)->vfunc_00(1);
    }
    r_esi = 0;
    if (m_Field00 > 0) {
        r_edi = (int)(&m_Field04);
        do {
            ((Object*)*(int*)r_edi)->vfunc_01();
            t4 = m_Field00;
            r_esi += 1;
            r_edi += 4;
        } while (r_esi < t4);
    }
}
