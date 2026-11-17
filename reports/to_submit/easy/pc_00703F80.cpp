// bin: pc
// va: 0x00703F80
// tool: the portal's starter code (no AI)
// sub_00703F80 (0x00703F80, 77 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00774894[];
extern "C" void __cdecl sub_0065C9B0(void);

class Class_00703F80
{
public:
    Class_00703F80* sub_00703F80(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0x8];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
    bool m_Field34; // +0x34
    bool m_Field35; // +0x35
    bool m_Field36; // +0x36
    char m_pad37[0x1];
    int m_Field38; // +0x38
    char m_pad3C[0x8];
    int m_Field44; // +0x44
    int m_Field48; // +0x48
};

Class_00703F80* Class_00703F80::sub_00703F80(int a1)
{
    sub_0065C9B0();
    m_Field18 = 0;
    m_Field1C = 0;
    m_Field20 = 0;
    m_Field24 = 0;
    m_Field28 = 0;
    m_Field2C = 0;
    m_Field30 = 0;
    m_Field34 = false;
    m_Field35 = false;
    m_Field36 = false;
    m_Field44 = 0;
    m_Field48 = 0;
    m_Field38 = a1;
    m_Field00 = (int)DAT_00774894;
    m_Field0C = *(int*)(*(int*)(a1 + 540) + 16);
    return this;
}
