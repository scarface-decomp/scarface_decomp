// bin: xb
// va: 0x001067B0
// tool: the portal's starter code (no AI)
// AIActionTreeCreatingTask::vfunc_29 (0x001067B0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

class AIActionTreeCreatingTask
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
    virtual bool vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual bool vfunc_43();
    char m_pad04[0x34];
    int m_Field38; // +0x38
    int m_Field3C; // +0x3C
    char m_pad40[0x9];
    unsigned char m_Field49; // +0x49
};

bool AIActionTreeCreatingTask::vfunc_29()
{
    int r_ebx, r_esi;
    bool t4;

    r_ebx = m_Field3C;
    r_esi = m_Field38;
    if (r_esi != r_ebx) {
        do {
            ((Object*)*(int*)r_esi)->vfunc_02();
            r_esi += 4;
        } while (r_esi != r_ebx);
    }
    vfunc_38();
    vfunc_42();
    t4 = vfunc_43();
    m_Field49 = t4;
    return t4;
}
