// bin: xb
// va: 0x0012EFD0
// tool: the portal's starter code (no AI)
// sub_0012EFD0 (0x0012EFD0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B142C[];

class Class_0012EFD0
{
public:
    Class_0012EFD0* sub_0012EFD0(int a1, float a2, float a3);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
};

Class_0012EFD0* Class_0012EFD0::sub_0012EFD0(int a1, float a2, float a3)
{
    m_Field18 = a2;
    m_Field1C = a3;
    m_Field04 = 5;
    m_Field00 = (int)DAT_003B142C;
    m_Field08 = a1;
    m_Field14 = 0.0f;
    m_Field10 = 0.0f;
    m_Field0C = 0.0f;
    return this;
}
