// bin: pc
// va: 0x00704290
// tool: the portal's starter code (no AI)
// pure3d::d3dPrimBufferStream::vfunc_07 (0x00704290, 41 bytes)
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
    virtual int vfunc_07(int a1, int a2, int a3);
    char m_pad04[0x44];
    int m_Field48; // +0x48
};

int d3dPrimBufferStream::vfunc_07(int a1, int a2, int a3)
{
    sub_00703DE0();
    *(int*)m_Field48 = a1;
    *(int*)(m_Field48 + 4) = a2;
    *(int*)(m_Field48 + 8) = a3;
    return a2;
}

}
