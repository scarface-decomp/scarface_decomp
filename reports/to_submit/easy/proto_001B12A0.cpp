// bin: proto
// va: 0x001B12A0
// tool: the portal's starter code (no AI)
// sub_001B12A0 (0x001B12A0, 96 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037FCE4;
extern "C" float DAT_003A1754;
extern "C" char DAT_003A2D1C[];

class Class_001B12A0
{
public:
    Class_001B12A0* sub_001B12A0(int a1, int a2);
    void sub_001A82B0(int, int, int, int, int, int);
    int m_Field00; // +0x00
    char m_pad04[0x78];
    int m_Field7C; // +0x7C
    int m_Field80; // +0x80
    char m_pad84[0x4C];
    float m_FieldD0; // +0xD0
    float m_FieldD4; // +0xD4
    char m_padD8[0x110];
    bool m_Field1E8; // +0x1E8
};

Class_001B12A0* Class_001B12A0::sub_001B12A0(int a1, int a2)
{
    float t3;

    sub_001A82B0(6, 1, 6, 0, a1, a2);
    m_FieldD4 = DAT_0037FCE4;
    t3 = DAT_003A1754;
    m_Field00 = (int)DAT_003A2D1C;
    m_Field1E8 = false;
    m_Field80 = 0;
    m_Field7C = 1;
    m_FieldD0 = t3;
    return this;
}
