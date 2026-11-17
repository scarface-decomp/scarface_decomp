// bin: xb
// va: 0x0023A590
// tool: the portal's starter code (no AI)
// sub_0023A590 (0x0023A590, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_0023A590
{
public:
    void sub_0023A590(int a1, int a2, int a3);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

void Class_0023A590::sub_0023A590(int a1, int a2, int a3)
{
    int r_edi, t2;

    r_edi = a3;
    m_Field00 = a1;
    m_Field04 = a2;
    if (a3) {
        ((Object*)r_edi)->vfunc_00();
    }
    t2 = m_Field08;
    if (m_Field08) {
        ((Object*)t2)->vfunc_01();
    }
    m_Field08 = r_edi;
    m_Field0C = 0;
    m_Field10 = 0;
}
