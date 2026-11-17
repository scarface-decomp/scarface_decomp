// bin: proto
// va: 0x001B7A20
// tool: the portal's starter code (no AI)
// sub_001B7A20 (0x001B7A20, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A3CE4[];

class Class_001B7A20
{
public:
    Class_001B7A20* sub_001B7A20(int a1, int a2);
    void sub_001B4CA0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x20];
    float m_Field24; // +0x24
};

Class_001B7A20* Class_001B7A20::sub_001B7A20(int a1, int a2)
{
    sub_001B4CA0(a1, a2);
    m_Field00 = (int)DAT_003A3CE4;
    m_Field24 = 0.0f;
    return this;
}
