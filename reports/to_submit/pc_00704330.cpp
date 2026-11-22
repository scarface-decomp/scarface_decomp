// bin: pc
// va: 0x00704330
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_18 (PC 0x00704330, 41 bytes)
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual int vfunc_18(int a1, int a2, int a3);
    char m_pad04[0x50];
    int m_Field54; // +0x54
};

int d3dPrimBufferStream::vfunc_18(int a1, int a2, int a3)
{
    sub_00703DE0();
    *(int*)m_Field54 = a1;
    *(int*)(m_Field54 + 4) = a2;
    *(int*)(m_Field54 + 8) = a3;
    return a2;
}

}
