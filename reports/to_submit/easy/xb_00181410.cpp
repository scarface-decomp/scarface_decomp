// bin: xb
// va: 0x00181410
// tool: the portal's starter code (no AI)
// NISSequenceBranchAction::vfunc_07 (0x00181410, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
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
    virtual float vfunc_23();
};

extern "C" float DAT_003D7E4C;

class NISSequenceBranchAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07(int a1);
    bool sub_00180E30();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    char m_pad0C[0x4];
    float m_Field10; // +0x10
};

int NISSequenceBranchAction::vfunc_07(int a1)
{
    m_Field10 = m_Field08->vfunc_23() * DAT_003D7E4C;
    return !sub_00180E30();
}
