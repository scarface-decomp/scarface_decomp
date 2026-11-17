// bin: proto
// va: 0x00099A40
// tool: the portal's starter code (no AI)
// sub_00099A40 (0x00099A40, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00384028[];

class Class_00099A40
{
public:
    Class_00099A40* sub_00099A40();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    bool m_Field08; // +0x08
    char m_pad09[0x3];
    bool m_Field0C; // +0x0C
    char m_pad0D[0x3];
    int m_Field10; // +0x10
    float m_Field14; // +0x14
};

Class_00099A40* Class_00099A40::sub_00099A40()
{
    m_Field04 = 0;
    m_Field08 = false;
    m_Field0C = false;
    m_Field00 = (int)DAT_00384028;
    m_Field10 = 0;
    m_Field14 = 0.0f;
    return this;
}
