// bin: pc
// va: 0x00703540
// tool: the portal's starter code (no AI)
// pure3d::d3dDevice::vfunc_12 (0x00703540, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00652AB0(int, int, int);

namespace pure3d {

class d3dDevice
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
    virtual void vfunc_12(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

void d3dDevice::vfunc_12(int a1, int a2)
{
    sub_00652AB0(m_Field0C, a1, 0);
}

}
