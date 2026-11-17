// bin: xb
// va: 0x00185080
// tool: the portal's starter code (no AI)
// sub_00185080 (0x00185080, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;
extern "C" char DAT_003B71CC[];
extern "C" float DAT_003D0FE4;
extern "C" void __cdecl sub_00022950(void);

class Class_00185080
{
public:
    Class_00185080* sub_00185080();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    int m_Field28; // +0x28
};

Class_00185080* Class_00185080::sub_00185080()
{
    float t2, t3;

    sub_00022950();
    t2 = DAT_003D0FE4;
    t3 = DAT_0039D65C;
    m_Field20 = 0;
    m_Field24 = 0;
    m_Field28 = 0;
    m_Field00 = (int)DAT_003B71CC;
    m_Field14 = t2;
    m_Field18 = t3;
    m_Field1C = t2;
    return this;
}
