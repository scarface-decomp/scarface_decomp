// bin: xb
// va: 0x001CC9A0
// tool: the portal's starter code (no AI)
// sub_001CC9A0 (0x001CC9A0, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field68
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
    int sub_001975D0();
};

struct Field7C
{
    void sub_00197B90();
};

extern "C" char DAT_003C4EDC[];
extern "C" int __cdecl sub_0006FB50(int, int);

class Class_001CC9A0
{
public:
    void sub_001CC9A0();
    void sub_001CC8C0(int);
    char m_pad00[0x68];
    Field68* m_Field68; // +0x68
    char m_pad6C[0x10];
    Field7C* m_Field7C; // +0x7C
};

void Class_001CC9A0::sub_001CC9A0()
{
    if (m_Field68) {
        if (!m_Field7C) goto L_44;
        if (m_Field68->sub_001975D0() <= 0) goto L_44;
        sub_001CC8C0(sub_0006FB50((int)DAT_003C4EDC, *(int*)(m_Field68->vfunc_07() + 8)));
        m_Field7C->sub_00197B90();
        return;
    }
L_44:
    ;
}
