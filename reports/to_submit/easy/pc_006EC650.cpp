// bin: pc
// va: 0x006EC650
// tool: the portal's starter code (no AI)
// sub_006EC650 (0x006EC650, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772544[];

class Class_006EC650
{
public:
    Class_006EC650* sub_006EC650(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

Class_006EC650* Class_006EC650::sub_006EC650(int a1)
{
    m_Field04 = 0;
    m_Field00 = (int)DAT_00772544;
    m_Field08 = a1;
    return this;
}
