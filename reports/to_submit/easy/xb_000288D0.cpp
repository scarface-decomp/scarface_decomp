// bin: xb
// va: 0x000288D0
// tool: the portal's starter code (no AI)
// sub_000288D0 (0x000288D0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual int vfunc_13();
};

struct Field70
{
    void sub_002511A0();
};

extern "C" void __cdecl sub_002E2930(void);

class Class_000288D0
{
public:
    void sub_000288D0();
    char m_pad00[0x10];
    Field10* m_Field10; // +0x10
    char m_pad14[0x5C];
    Field70* m_Field70; // +0x70
};

void Class_000288D0::sub_000288D0()
{
    if (!m_Field70) goto L_3F;
    if (m_Field10->vfunc_13() != 4) goto L_38;
L_17:
    if (!*(bool*)((int)m_Field70 + 4)) {
        m_Field70->sub_002511A0();
        sub_002E2930();
        if (m_Field10->vfunc_13() == 4) goto L_17;
    }
L_38:
    *(bool*)((int)m_Field70 + 4) = false;
L_3F:
    ;
}
