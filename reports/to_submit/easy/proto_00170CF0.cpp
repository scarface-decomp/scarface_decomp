// bin: proto
// va: 0x00170CF0
// tool: the portal's starter code (no AI)
// sub_00170CF0 (0x00170CF0, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_00398740[];
extern "C" void __cdecl sub_00201990(int, int);

class Class_00170CF0
{
public:
    void sub_00170CF0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

void Class_00170CF0::sub_00170CF0()
{
    int r_ebx, r_edi, t1, t3, t4;

    r_ebx = m_Field08;
    r_edi = m_Field04;
    m_Field00 = (int)DAT_00398740;
    if (r_edi != r_ebx) {
        do {
            t1 = *(int*)r_edi;
            if (*(int*)r_edi) {
                ((Object*)t1)->vfunc_00(1);
            }
            t3 = m_Field04;
            r_edi += 4;
            m_Field08 = t3;
        } while (r_edi != r_ebx);
    }
    t4 = m_Field04;
    m_Field08 = m_Field04;
    if (m_Field04) {
        sub_00201990(7, t4);
    }
}
