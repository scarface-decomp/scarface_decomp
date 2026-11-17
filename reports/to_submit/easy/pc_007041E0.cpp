// bin: pc
// va: 0x007041E0
// tool: the portal's starter code (no AI)
// pure3d::d3dPrimBufferStream::vfunc_13 (0x007041E0, 37 bytes)
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
    virtual int vfunc_13(float a1, float a2, int a3);
    char m_pad04[0x34];
    int m_Field38; // +0x38
};

int d3dPrimBufferStream::vfunc_13(float a1, float a2, int a3)
{
    sub_00703DE0();
    *(float*)(m_Field38 + (a3 * 8)) = a1;
    *(float*)(m_Field38 + (a3 * 8) + 4) = a2;
    return a3;
}

}
