// bin: pc
// va: 0x00704260
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_10 (PC 0x00704260, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

namespace pure3d {

class d3dPrimBufferStream
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
    virtual int vfunc_10(int a1, int a2, int a3);
    char m_pad04[0x3C];
    int m_Field40; // +0x40
};

int d3dPrimBufferStream::vfunc_10(int a1, int a2, int a3)
{
    sub_00703DE0();
    *(int*)m_Field40 = a1;
    *(int*)(m_Field40 + 4) = a2;
    *(int*)(m_Field40 + 8) = a3;
    return a2;
}

}
