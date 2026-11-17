// bin: xb
// va: 0x00292E70
// tool: the portal's starter code (no AI)
// sub_00292E70 (0x00292E70, 89 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_003D8D54[];
extern "C" void __stdcall sub_0025D110(int);

class Class_00292E70
{
public:
    Class_00292E70* sub_00292E70(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x34];
    int m_Field38; // +0x38
    int m_Field3C; // +0x3C
    int m_Field40; // +0x40
    int m_Field44; // +0x44
    int m_Field48; // +0x48
};

Class_00292E70* Class_00292E70::sub_00292E70(int a1)
{
    int r_edi, t3;

    r_edi = a1;
    sub_0025D110(a1);
    m_Field00 = (int)DAT_003D8D54;
    m_Field38 = 0;
    m_Field3C = *(int*)(r_edi + 60);
    m_Field40 = *(int*)(r_edi + 64);
    m_Field44 = *(int*)(r_edi + 68);
    m_Field48 = *(int*)(r_edi + 72);
    r_edi = *(int*)(r_edi + 56);
    if (r_edi) {
        ((Object*)r_edi)->vfunc_00();
    }
    t3 = m_Field38;
    if (m_Field38) {
        ((Object*)t3)->vfunc_01();
    }
    m_Field38 = r_edi;
    return this;
}
