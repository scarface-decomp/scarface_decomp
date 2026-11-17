// bin: xb
// va: 0x000E4290
// tool: the portal's starter code (no AI)
// DismemberAction::vfunc_08 (0x000E4290, 61 bytes)
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
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual int vfunc_39();
    void sub_00164D20();
};

extern "C" int DAT_0048A9D8;
extern "C" void __cdecl sub_00048EB0(int);

class DismemberAction
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
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

void DismemberAction::vfunc_08()
{
    int t1, t2, t3;

    t1 = *(int*)(m_Field0C + 80);
    if (*(int*)(m_Field0C + 80)) {
        t2 = DAT_0048A9D8;
        if (!DAT_0048A9D8) goto L_3B;
        if (t1 != t2) goto L_3B;
        t3 = ((Object*)t1)->vfunc_39();
        if (t3) {
            sub_00048EB0(t3);
        }
        ((Object*)*(int*)(m_Field0C + 80))->sub_00164D20();
        return;
    }
L_3B:
    ;
}
