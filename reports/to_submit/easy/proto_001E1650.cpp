// bin: proto
// va: 0x001E1650
// tool: the portal's starter code (no AI)
// sub_001E1650 (0x001E1650, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001E1650
{
public:
    void sub_001E1650(float a1);
    char m_pad00[0x40];
    float m_Field40; // +0x40
};

void Class_001E1650::sub_001E1650(float a1)
{
    m_Field40 = a1 * a1;
}
