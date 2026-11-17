// bin: xb
// va: 0x0013CAD0
// tool: the portal's starter code (no AI)
// BoatAITask_Enemy::vfunc_34 (0x0013CAD0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003B21AC;

class BoatAITask_Enemy
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
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    char m_pad04[0x40];
    int m_Field44; // +0x44
    char m_pad48[0xC];
    int m_Field54; // +0x54
    float m_Field58; // +0x58
    int m_Field5C; // +0x5C
};

void BoatAITask_Enemy::vfunc_34()
{
    float t1;

    t1 = DAT_003B21AC;
    m_Field54 = -1;
    m_Field58 = t1;
    m_Field5C = 1;
    m_Field44 = 0;
}
