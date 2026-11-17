// bin: xb
// va: 0x0017EC30
// tool: the portal's starter code (no AI)
// NISCharacterAnimationAction::vfunc_08 (0x0017EC30, 76 bytes)
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
    virtual void vfunc_07();
    virtual void vfunc_08(int, int);
    void sub_000D8530();
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
    virtual void vfunc_08();
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

void NISCharacterAnimationAction::vfunc_08()
{
    int t1, t2, t3, t5, t6;

    t1 = m_Field10;
    if (!m_Field10) goto L_4B;
    t2 = *(int*)(t1 + 428);
    if (!*(int*)(t1 + 428)) goto L_4B;
    t3 = *(int*)(t2 + 376);
    if (*(int*)(t2 + 376)) {
        *(int*)(t3 + 320) = 0;
        ((Object*)t3)->sub_000D8530();
        t5 = *(int*)(t3 + 12);
        if (!*(int*)(t3 + 12)) goto L_4A;
        t6 = *(int*)(t5 + 12);
        if (!*(int*)(t5 + 12)) goto L_4A;
        ((Object*)t6)->vfunc_08(0, 0);
        *(bool*)(t6 + 36) = false;
    }
L_4A:
L_4B:
    ;
}
