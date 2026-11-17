// bin: proto
// va: 0x0009ADC0
// tool: the portal's starter code (no AI)
// sub_0009ADC0 (0x0009ADC0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037D4B8;
extern "C" float DAT_00390144;

class Class_0009ADC0
{
public:
    Class_0009ADC0* sub_0009ADC0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

Class_0009ADC0* Class_0009ADC0::sub_0009ADC0()
{
    float t2;

    m_Field08 = DAT_0037D4B8;
    t2 = DAT_00390144;
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field0C = t2;
    return this;
}
