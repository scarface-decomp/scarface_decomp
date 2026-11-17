// bin: xb
// va: 0x002602D0
// tool: the portal's starter code (no AI)
// sub_002602D0 (0x002602D0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_002602D0
{
public:
    void sub_002602D0(int a1, int a2);
    char m_pad00[0x14];
    int m_Field14; // +0x14
};

void Class_002602D0::sub_002602D0(int a1, int a2)
{
    int r_edi, r_esi, t2;

    r_edi = a2;
    r_esi = m_Field14 + (a1 * 4);
    if (a2) {
        ((Object*)r_edi)->vfunc_00();
    }
    t2 = *(int*)r_esi;
    if (*(int*)r_esi) {
        ((Object*)t2)->vfunc_01();
    }
    *(int*)r_esi = r_edi;
}
