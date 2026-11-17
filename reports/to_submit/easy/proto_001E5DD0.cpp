// bin: proto
// va: 0x001E5DD0
// tool: the portal's starter code (no AI)
// sub_001E5DD0 (0x001E5DD0, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AB114[];

class Class_001E5DD0
{
public:
    Class_001E5DD0* sub_001E5DD0(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    float m_Field28; // +0x28
};

Class_001E5DD0* Class_001E5DD0::sub_001E5DD0(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field20 = 0;
    m_Field24 = 0;
    m_Field00 = (int)DAT_003AB114;
    m_Field28 = 0.0f;
    return this;
}
