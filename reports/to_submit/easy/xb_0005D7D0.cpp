// bin: xb
// va: 0x0005D7D0
// tool: the portal's starter code (no AI)
// sub_0005D7D0 (0x0005D7D0, 77 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A15C4[];
extern "C" void __stdcall sub_00059490(int);

class Class_0005D7D0
{
public:
    Class_0005D7D0* sub_0005D7D0();
    int m_Field00; // +0x00
    char m_pad04[0x50];
    int m_Field54; // +0x54
    char m_pad58[0x4C];
    int m_FieldA4; // +0xA4
    float m_FieldA8; // +0xA8
    bool m_FieldAC; // +0xAC
    char m_padAD[0x3];
    int m_FieldB0; // +0xB0
    int m_FieldB4; // +0xB4
    int m_FieldB8; // +0xB8
    int m_FieldBC; // +0xBC
};

Class_0005D7D0* Class_0005D7D0::sub_0005D7D0()
{
    sub_00059490(0);
    m_FieldA4 = 0;
    m_FieldAC = false;
    m_FieldB0 = 0;
    m_FieldB4 = 0;
    m_FieldB8 = 0;
    m_FieldBC = 0;
    m_Field00 = (int)DAT_003A15C4;
    m_FieldA8 = 0.0f;
    m_Field54 = 16384;
    return this;
}
