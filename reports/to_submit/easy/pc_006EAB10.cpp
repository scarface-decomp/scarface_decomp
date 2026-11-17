// bin: pc
// va: 0x006EAB10
// tool: the portal's starter code (no AI)
// sub_006EAB10 (0x006EAB10, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int, int, int);
};

class Class_006EAB10
{
public:
    bool sub_006EAB10(int a1, int a2, int a3, int a4);
    void sub_006EA9E0();
    void sub_006EAA20(int, int, int);
    char m_pad00[0x8];
    Field08* m_Field08; // +0x08
    char m_pad0C[0xC];
    int m_Field18; // +0x18
};

bool Class_006EAB10::sub_006EAB10(int a1, int a2, int a3, int a4)
{
    m_Field08->vfunc_04(a1, a2 * a3, a4);
    m_Field18 += a2 * a3;
    sub_006EA9E0();
    sub_006EAA20(a1, a2, a3);
    return true;
}
