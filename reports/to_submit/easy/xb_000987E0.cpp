// bin: xb
// va: 0x000987E0
// tool: the portal's starter code (no AI)
// sub_000987E0 (0x000987E0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000987E0
{
public:
    Class_000987E0* sub_000987E0(float a1, float a2);
    float m_Field00; // +0x00
    float m_Field04; // +0x04
};

Class_000987E0* Class_000987E0::sub_000987E0(float a1, float a2)
{
    m_Field00 = a1;
    m_Field04 = a2;
    return this;
}
