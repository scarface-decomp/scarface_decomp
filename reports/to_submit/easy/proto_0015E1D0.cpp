// bin: proto
// va: 0x0015E1D0
// tool: the portal's starter code (no AI)
// NISCharacterAnimationAction::vfunc_07 (0x0015E1D0, 76 bytes)
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
    virtual void vfunc_07(int, int);
    void sub_000C6970();
};

class NISCharacterAnimationAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

void NISCharacterAnimationAction::vfunc_07()
{
    int t1, t2, t3, t5, t6;

    t1 = m_Field10;
    if (!m_Field10) goto L_4B;
    t2 = *(int*)(t1 + 392);
    if (!*(int*)(t1 + 392)) goto L_4B;
    t3 = *(int*)(t2 + 384);
    if (*(int*)(t2 + 384)) {
        *(int*)(t3 + 332) = 0;
        ((Object*)t3)->sub_000C6970();
        t5 = *(int*)(t3 + 12);
        if (!*(int*)(t3 + 12)) goto L_4A;
        t6 = *(int*)(t5 + 12);
        if (!*(int*)(t5 + 12)) goto L_4A;
        ((Object*)t6)->vfunc_07(0, 0);
        *(bool*)(t6 + 36) = false;
    }
L_4A:
L_4B:
    ;
}
