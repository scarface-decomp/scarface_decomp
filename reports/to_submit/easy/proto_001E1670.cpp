// bin: proto
// va: 0x001E1670
// tool: the portal's starter code (no AI)
// sub_001E1670 (0x001E1670, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001E1670
{
public:
    void sub_001E1670(float a1);
    char m_pad00[0x3C];
    float m_Field3C; // +0x3C
};

void Class_001E1670::sub_001E1670(float a1)
{
    m_Field3C = a1 * a1;
}
