// bin: xb
// va: 0x001F2110
// tool: the portal's starter code (no AI)
// sub_001F2110 (0x001F2110, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CA01C[];

class Class_001F2110
{
public:
    Class_001F2110* sub_001F2110(int a1, int a2);
    void sub_001EEC80(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x20];
    float m_Field24; // +0x24
};

Class_001F2110* Class_001F2110::sub_001F2110(int a1, int a2)
{
    sub_001EEC80(a1, a2);
    m_Field00 = (int)DAT_003CA01C;
    m_Field24 = 0.0f;
    return this;
}
