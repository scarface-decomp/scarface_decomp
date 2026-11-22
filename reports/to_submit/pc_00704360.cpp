// bin: pc
// va: 0x00704360
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_23 (PC 0x00704360, 51 bytes)
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
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23(int a1, int a2);
    void sub_007037B0();
    char m_pad04[0x20];
    int m_Field24; // +0x24
    char m_pad28[0x8];
    int m_Field30; // +0x30
};

void d3dPrimBufferStream::vfunc_23(int a1, int a2)
{
    int t2;

    sub_00703DE0();
    t2 = m_Field24;
    *(int*)m_Field24 = *(int*)a1;
    *(int*)(t2 + 4) = *(int*)(a1 + 4);
    *(int*)(t2 + 8) = *(int*)(a1 + 8);
    *(int*)m_Field30 = a2;
    sub_007037B0();
}

}
