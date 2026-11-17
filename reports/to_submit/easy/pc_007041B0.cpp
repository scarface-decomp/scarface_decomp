// bin: pc
// va: 0x007041B0
// tool: the portal's starter code (no AI)
// pure3d::d3dPrimBufferStream::vfunc_11 (0x007041B0, 42 bytes)
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
    virtual int vfunc_11(int a1, int a2);
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    char m_pad34[0x10];
    int m_Field44; // +0x44
};

int d3dPrimBufferStream::vfunc_11(int a1, int a2)
{
    int r_eax, r_edx;

    sub_00703DE0();
    r_eax = a2;
    r_edx = a1;
    if (a2 < 2) {
        *(int*)(m_Field30 + (r_eax * 4)) = a1;
        return r_eax;
    }
    *(int*)(m_Field44 + (r_eax * 4) + -8) = r_edx;
    return r_eax;
}

}
