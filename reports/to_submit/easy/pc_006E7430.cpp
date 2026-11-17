// bin: pc
// va: 0x006E7430
// tool: the portal's starter code (no AI)
// sub_006E7430 (0x006E7430, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" int DAT_0072F0FC;
extern "C" char DAT_00772320[];
extern "C" char DAT_00772330[];
extern "C" char DAT_0077233C[];
extern "C" void __cdecl sub_006DF060(int);

class Class_006E7430
{
public:
    void sub_006E7430();
    void sub_006E6030();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    char m_pad08[0x4];
    int m_Field0C; // +0x0C
    char m_pad10[0xC0];
    int m_FieldD0; // +0xD0
    char m_padD4[0x4];
    int m_FieldD8; // +0xD8
    char m_padDC[0x1C];
    int m_FieldF8; // +0xF8
};

void Class_006E7430::sub_006E7430()
{
    int t1;

    t1 = m_FieldD0;
    m_Field00 = (int)DAT_0077233C;
    m_Field04 = (int)DAT_00772330;
    m_Field0C = (int)DAT_00772320;
    ((Object*)t1)->vfunc_01();
    m_FieldD0 = 0;
    sub_006DF060((int)(&m_FieldF8));
    ((void (__stdcall*)(int))DAT_0072F0FC)(m_FieldD8);
    sub_006E6030();
}
