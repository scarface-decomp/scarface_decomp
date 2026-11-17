// bin: xb
// va: 0x0023E4E0
// tool: the portal's starter code (no AI)
// sub_0023E4E0 (0x0023E4E0, 96 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    void sub_00239EE0();
    void sub_00242D20(int);
    void sub_00242D70(int);
};

extern "C" char DAT_003D46F4[];
extern "C" char DAT_003D4738[];
extern "C" int __cdecl sub_0023F760(int);
extern "C" void __cdecl sub_00242DA0(void);

class Class_0023E4E0
{
public:
    Class_0023E4E0* sub_0023E4E0(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

Class_0023E4E0* Class_0023E4E0::sub_0023E4E0(int a1)
{
    int r_ebx, r_ecx, t3;

    r_ecx = (int)this;
    sub_00242DA0();
    r_ebx = (int)(&m_Field08);
    r_ecx = (int)(&m_Field08);
    m_Field00 = (int)DAT_003D4738;
    ((Object*)r_ecx)->sub_00242D70(a1);
    t3 = sub_0023F760(16);
    if (t3) {
        r_ecx = t3;
        ((Object*)r_ecx)->sub_00239EE0();
        *(int*)t3 = (int)DAT_003D46F4;
        r_ecx = t3;
    } else {
        r_ecx = 0;
    }
    m_Field0C = r_ecx;
    ((Object*)r_ecx)->vfunc_00();
    r_ecx = m_Field0C;
    r_ecx += 8;
    ((Object*)r_ecx)->sub_00242D20(r_ebx);
    return this;
}
