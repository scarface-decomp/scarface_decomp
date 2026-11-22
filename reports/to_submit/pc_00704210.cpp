// bin: pc
// va: 0x00704210
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dPrimBufferStream::vfunc_16 (PC 0x00704210, 21 bytes)
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
    virtual int vfunc_16(int a1);
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

int d3dPrimBufferStream::vfunc_16(int a1)
{
    int t2;

    sub_00703DE0();
    t2 = m_Field34;
    *(int*)m_Field34 = a1;
    return t2;
}

}
