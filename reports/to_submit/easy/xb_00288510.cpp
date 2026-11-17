// bin: xb
// va: 0x00288510
// tool: the portal's starter code (no AI)
// sub_00288510 (0x00288510, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_0039E22C[];
extern "C" char DAT_003D8240[];

class Class_00288510
{
public:
    void sub_00288510();
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

void Class_00288510::sub_00288510()
{
    int r_ebx, r_esi, t1, t3;

    r_ebx = 0;
    m_Field00 = (int)DAT_003D8240;
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
    m_Field00 = (int)DAT_0039E22C;
}
