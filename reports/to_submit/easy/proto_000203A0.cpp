// bin: proto
// va: 0x000203A0
// tool: the portal's starter code (no AI)
// FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_26 (0x000203A0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace fight { class EnterExitScriptTrack; }

namespace FightTree { 
template <class T0> class FightActionController
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
    virtual bool vfunc_26(float a1);
    char m_pad04[0xC];
    float m_Field10; // +0x10
};
}

template <> bool FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_26(float a1)
{
    m_Field10 = a1;
    return true;
}
