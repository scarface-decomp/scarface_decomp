// bin: pc
// va: 0x00704070
// tool: the portal's starter code (no AI)
// pure3d::d3dPrimBufferStream::vfunc_00 (0x00704070, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703DE0(void);

namespace pure3d {

class d3dPrimBufferStream
{
public:
    virtual void vfunc_00(int a1, int a2, int a3);
    void sub_007037B0();
    char m_pad04[0x20];
    int m_Field24; // +0x24
};

void d3dPrimBufferStream::vfunc_00(int a1, int a2, int a3)
{
    sub_00703DE0();
    *(int*)m_Field24 = a1;
    *(int*)(m_Field24 + 4) = a2;
    *(int*)(m_Field24 + 8) = a3;
    sub_007037B0();
}

}
