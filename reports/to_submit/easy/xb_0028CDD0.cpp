// bin: xb
// va: 0x0028CDD0
// tool: the portal's starter code (no AI)
// sub_0028CDD0 (0x0028CDD0, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_0028CDD0
{
public:
    void sub_0028CDD0(int a1);
    char m_pad00[0x38];
    int m_Field38; // +0x38
};

void Class_0028CDD0::sub_0028CDD0(int a1)
{
    int r_esi, t2;

    r_esi = *(int*)(a1 + 104);
    if (r_esi) {
        ((Object*)r_esi)->vfunc_00();
    }
    t2 = m_Field38;
    if (m_Field38) {
        ((Object*)t2)->vfunc_01();
    }
    m_Field38 = r_esi;
}
