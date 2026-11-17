// bin: xb
// va: 0x00292B60
// tool: the portal's starter code (no AI)
// pure3d::PrimGroupStreamed::vfunc_17 (0x00292B60, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Field50
{
    void sub_002B73C0(int, int, int);
};

namespace pure3d {

class PrimGroupStreamed
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
    virtual void vfunc_17(int a1);
    char m_pad04[0x4C];
    Field50* m_Field50; // +0x50
};

void PrimGroupStreamed::vfunc_17(int a1)
{
    m_Field50->sub_002B73C0(a1, 0, 0);
}

}
