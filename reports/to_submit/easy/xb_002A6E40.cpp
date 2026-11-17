// bin: xb
// va: 0x002A6E40
// tool: the portal's starter code (no AI)
// sub_002A6E40 (0x002A6E40, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_002A6E40
{
public:
    void sub_002A6E40(int a1);
    char m_pad00[0x34];
    int m_Field34; // +0x34
};

void Class_002A6E40::sub_002A6E40(int a1)
{
    int r_esi, t2;

    r_esi = *(int*)(a1 + 96);
    if (r_esi) {
        ((Object*)r_esi)->vfunc_00();
    }
    t2 = m_Field34;
    if (m_Field34) {
        ((Object*)t2)->vfunc_01();
    }
    m_Field34 = r_esi;
}
