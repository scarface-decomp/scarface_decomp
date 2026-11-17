// bin: proto
// va: 0x00244790
// tool: the portal's starter code (no AI)
// sub_00244790 (0x00244790, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_0037D85C[];
extern "C" char DAT_003B13A0[];

class Class_00244790
{
public:
    void sub_00244790();
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

void Class_00244790::sub_00244790()
{
    int r_ebx, r_esi, t1, t3;

    r_ebx = 0;
    m_Field00 = (int)DAT_003B13A0;
    if (m_Field08 > 0) {
        r_esi = (int)(&m_Field0C);
        do {
            t1 = *(int*)r_esi;
            if (*(int*)r_esi) {
                ((Object*)t1)->vfunc_01();
                *(int*)r_esi = 0;
            }
            t3 = m_Field08;
            r_ebx += 1;
            r_esi += 4;
        } while (r_ebx < t3);
    }
    m_Field00 = (int)DAT_0037D85C;
}
