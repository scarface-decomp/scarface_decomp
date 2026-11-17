// bin: xb
// va: 0x001C3580
// tool: the portal's starter code (no AI)
// sub_001C3580 (0x001C3580, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001C3580
{
public:
    void sub_001C3580(float a1);
    char m_pad00[0x150];
    float m_Field150; // +0x150
    float m_Field154; // +0x154
};

void Class_001C3580::sub_001C3580(float a1)
{
    m_Field150 = 0.0f;
    m_Field154 = a1;
}
