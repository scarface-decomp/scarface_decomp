// bin: proto
// va: 0x001C46C0
// tool: the portal's starter code (no AI)
// sub_001C46C0 (0x001C46C0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A5464[];

class Class_001C46C0
{
public:
    Class_001C46C0* sub_001C46C0(int a1, int a2);
    void sub_001C43F0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0xB1];
    bool m_FieldB5; // +0xB5
    char m_padB6[0x22];
    int m_FieldD8; // +0xD8
    int m_FieldDC; // +0xDC
    float m_FieldE0; // +0xE0
};

Class_001C46C0* Class_001C46C0::sub_001C46C0(int a1, int a2)
{
    sub_001C43F0(a1, a2);
    m_FieldD8 = 0;
    m_FieldDC = 0;
    m_Field00 = (int)DAT_003A5464;
    m_FieldE0 = 0.0f;
    m_FieldB5 = true;
    return this;
}
