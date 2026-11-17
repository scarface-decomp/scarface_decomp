// bin: xb
// va: 0x00239FD0
// tool: the portal's starter code (no AI)
// sub_00239FD0 (0x00239FD0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field18
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int);
};

extern "C" void __cdecl sub_0023A7B0(void);

class Class_00239FD0
{
public:
    void sub_00239FD0();
    char m_pad00[0x14];
    int m_Field14; // +0x14
    Field18* m_Field18; // +0x18
};

void Class_00239FD0::sub_00239FD0()
{
    sub_0023A7B0();
    if (m_Field14) {
        m_Field18->vfunc_06(0);
    }
}
