// bin: proto
// va: 0x00171FD0
// tool: the portal's starter code (no AI)
// sub_00171FD0 (0x00171FD0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00398B2C[];
extern "C" char DAT_00398B34[];

class Class_00171FD0
{
public:
    Class_00171FD0* sub_00171FD0(int a1, int a2);
    void sub_00171AC0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    char m_pad44[0x30];
    float m_Field74; // +0x74
    float m_Field78; // +0x78
};

Class_00171FD0* Class_00171FD0::sub_00171FD0(int a1, int a2)
{
    sub_00171AC0(a1, a2);
    m_Field00 = (int)DAT_00398B34;
    m_Field40 = (int)DAT_00398B2C;
    m_Field74 = 0.0f;
    m_Field78 = 0.0f;
    return this;
}
