// bin: pc
// va: 0x006FF3A0
// tool: the portal's starter code (no AI)
// sub_006FF3A0 (0x006FF3A0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006FF3A0
{
public:
    Class_006FF3A0* sub_006FF3A0();
    char m_pad00[0x10];
    int m_Field10; // +0x10
    char m_pad14[0x4];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

Class_006FF3A0* Class_006FF3A0::sub_006FF3A0()
{
    m_Field10 = 0;
    m_Field18 = 0;
    m_Field1C = 0;
    return this;
}
