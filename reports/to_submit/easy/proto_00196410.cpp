// bin: proto
// va: 0x00196410
// tool: the portal's starter code (no AI)
// sub_00196410 (0x00196410, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039F5F4[];
extern "C" char DAT_0039F60C[];

class Class_00196410
{
public:
    Class_00196410* sub_00196410(int a1, int a2);
    void sub_00193E40(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    char m_pad44[0x14];
    int m_Field58; // +0x58
    float m_Field5C; // +0x5C
    bool m_Field60; // +0x60
};

Class_00196410* Class_00196410::sub_00196410(int a1, int a2)
{
    sub_00193E40(a1, a2);
    m_Field58 = 0;
    m_Field60 = false;
    m_Field00 = (int)DAT_0039F60C;
    m_Field40 = (int)DAT_0039F5F4;
    m_Field5C = 0.0f;
    return this;
}
