// bin: proto
// va: 0x0015FBC0
// what: 
// tool: the portal's starter code (no AI)

// NISSequenceBranchAction::vfunc_11 (Proto 0x0015FBC0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_0015F930(void);

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
    virtual int vfunc_11(int a1);
};

int NISSequenceBranchAction::vfunc_11(int a1)
{
    return !sub_0015F930();
}
