// bin: xb
// va: 0x001C2760
// tool: the portal's starter code (no AI)
// sub_001C2760 (0x001C2760, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;
extern "C" char DAT_003C2CEC[];

class Class_001C2760
{
public:
    Class_001C2760* sub_001C2760(int a1, int a2);
    void sub_001930D0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x60];
    int m_Field64; // +0x64
    int m_Field68; // +0x68
    float m_Field6C; // +0x6C
    float m_Field70; // +0x70
    float m_Field74; // +0x74
    float m_Field78; // +0x78
};

Class_001C2760* Class_001C2760::sub_001C2760(int a1, int a2)
{
    sub_001930D0(a1, a2);
    m_Field64 = 0;
    m_Field68 = 0;
    m_Field00 = (int)DAT_003C2CEC;
    m_Field6C = 0.0f;
    m_Field70 = 0.0f;
    m_Field74 = 0.0f;
    m_Field78 = DAT_0039D664;
    return this;
}
