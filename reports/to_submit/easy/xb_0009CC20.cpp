// bin: xb
// va: 0x0009CC20
// tool: the portal's starter code (no AI)
// WheeledLocomotion::vfunc_02 (0x0009CC20, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_000C23C0();
};

struct Object
{
    void sub_000BD120(int, int);
};

extern "C" void __stdcall sub_00022710(int);

class WheeledLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

void WheeledLocomotion::vfunc_02(int a1)
{
    int r_ebp, r_ebx, r_edi, t4;

    sub_00022710(a1);
    r_ebp = m_Field08->sub_000C23C0();
    if (r_ebp) {
        r_edi = 0;
        if (m_Field0C > 0) {
            r_ebx = 0;
            do {
                ((Object*)m_Field10 + r_ebx)->sub_000BD120(a1, r_ebp);
                t4 = m_Field0C;
                r_edi += 1;
                r_ebx += 548;
            } while (r_edi < t4);
        }
    }
}
