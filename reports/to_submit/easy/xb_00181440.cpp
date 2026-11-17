// bin: xb
// va: 0x00181440
// tool: the portal's starter code (no AI)
// NISSequenceBranchAction::vfunc_12 (0x00181440, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_00180E30(void);

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
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12(int a1);
};

int NISSequenceBranchAction::vfunc_12(int a1)
{
    return !sub_00180E30();
}
