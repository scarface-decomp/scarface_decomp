// bin: pc
// va: 0x00703B30
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBuffer::vfunc_10 (PC 0x00703B30, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class d3dPrimBuffer
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
    virtual int vfunc_10(int a1);
};

int d3dPrimBuffer::vfunc_10(int a1)
{
    return a1 == 0x20001;
}

}
