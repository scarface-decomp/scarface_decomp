// bin: xb
// va: 0x000E80B0
// tool: the portal's starter code (no AI)
// sub_000E80B0 (0x000E80B0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A83A4[];
extern "C" void __cdecl sub_00022990(void);

class Class_000E80B0
{
public:
    Class_000E80B0* sub_000E80B0();
    int m_Field00; // +0x00
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    float m_Field28; // +0x28
};

Class_000E80B0* Class_000E80B0::sub_000E80B0()
{
    sub_00022990();
    m_Field00 = (int)DAT_003A83A4;
    m_Field1C = 0;
    m_Field20 = 0.0f;
    m_Field24 = 0.0f;
    m_Field28 = 0.0f;
    return this;
}
