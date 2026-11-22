// bin: proto
// va: 0x0008CEF0
// what: 
// tool: the portal's starter code (no AI)

// sub_0008CEF0 (Proto 0x0008CEF0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0008CEF0
{
public:
    Class_0008CEF0* sub_0008CEF0(float a1, float a2);
    float m_Field00; // +0x00
    float m_Field04; // +0x04
};

Class_0008CEF0* Class_0008CEF0::sub_0008CEF0(float a1, float a2)
{
    m_Field00 = a1;
    m_Field04 = a2;
    return this;
}
