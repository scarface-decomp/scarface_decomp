// bin: xb
// va: 0x0017EE20
// tool: the portal's starter code (no AI)
// sub_0017EE20 (0x0017EE20, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
};

extern "C" char DAT_003B638C[];
extern "C" void __cdecl sub_000217D0(void);

class Class_0017EE20
{
public:
    Class_0017EE20* sub_0017EE20(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_0017EE20* Class_0017EE20::sub_0017EE20(int a1, int a2)
{
    sub_000217D0();
    m_Field00 = (int)DAT_003B638C;
    m_Field08 = a1;
    m_Field0C = a2;
    m_Field10 = 0.0f;
    ((Object*)a1)->vfunc_00();
    return this;
}
