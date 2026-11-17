// bin: proto
// va: 0x00132AC0
// tool: the portal's starter code (no AI)
// sub_00132AC0 (0x00132AC0, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldE8
{
    void sub_00135AE0();
};

extern "C" char DAT_00390E2C[];

class Class_00132AC0
{
public:
    Class_00132AC0* sub_00132AC0(int a1, int a2);
    void sub_00136050(int, int);
    int m_Field00; // +0x00
    char m_pad04[0xA8];
    int m_FieldAC; // +0xAC
    int m_FieldB0; // +0xB0
    char m_padB4[0x8];
    float m_FieldBC; // +0xBC
    char m_padC0[0x28];
    FieldE8 m_FieldE8; // +0xE8
    char m_padE9[0x3];
    int m_FieldEC; // +0xEC
};

Class_00132AC0* Class_00132AC0::sub_00132AC0(int a1, int a2)
{
    sub_00136050(a1, a2);
    m_Field00 = (int)DAT_00390E2C;
    m_FieldE8.sub_00135AE0();
    m_FieldB0 = 0;
    m_FieldAC = 0;
    m_FieldEC = 0;
    m_FieldBC = 0.0f;
    return this;
}
