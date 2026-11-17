// bin: proto
// va: 0x00045FD0
// tool: the portal's starter code (no AI)
// sub_00045FD0 (0x00045FD0, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
};

extern "C" char DAT_0037F9CC[];
extern "C" void __cdecl sub_002C9907(int, int);

class Class_00045FD0
{
public:
    void sub_00045FD0(int a1);
    char m_pad00[0x4];
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

void Class_00045FD0::sub_00045FD0(int a1)
{
    int r_ebp, r_edi, r_esi, t1;

    r_esi = m_Field08;
    r_esi -= m_Field04;
    r_esi >>= 2;
    r_edi = 0;
    if (r_esi <= 0) goto L_48;
    r_ebp = a1;
L_20:
    t1 = *(int*)(m_Field04 + (r_edi * 4));
    if (*(int*)(m_Field04 + (r_edi * 4))) {
        if (*(int*)(t1 + 84) != r_ebp) goto L_42;
        sub_002C9907((int)DAT_0037F9CC, ((Object*)t1)->vfunc_07());
    }
L_42:
    r_edi += 1;
    if (r_edi < r_esi) goto L_20;
L_48:
    ;
}
