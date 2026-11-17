// bin: xb
// va: 0x00146F60
// tool: the portal's starter code (no AI)
// sub_00146F60 (0x00146F60, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B265C[];

class Class_00146F60
{
public:
    Class_00146F60* sub_00146F60(int a1, int a2);
    void sub_00146140(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x34];
    int m_Field38; // +0x38
    int m_Field3C; // +0x3C
    int m_Field40; // +0x40
    char m_pad44[0x1];
    bool m_Field45; // +0x45
    char m_pad46[0x2];
    float m_Field48; // +0x48
    float m_Field4C; // +0x4C
};

Class_00146F60* Class_00146F60::sub_00146F60(int a1, int a2)
{
    sub_00146140(a1, a2);
    m_Field38 = 0;
    m_Field3C = 0;
    m_Field40 = 0;
    m_Field00 = (int)DAT_003B265C;
    m_Field45 = true;
    m_Field48 = 0.0f;
    m_Field4C = 0.0f;
    return this;
}
