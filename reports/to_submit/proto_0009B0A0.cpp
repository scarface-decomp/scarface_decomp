// bin: proto
// va: 0x0009B0A0
// what: 
// tool: the portal's starter code (no AI)

// sub_0009B0A0 (Proto 0x0009B0A0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_00384640;

class Class_0009B0A0
{
public:
    void sub_0009B0A0();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

void Class_0009B0A0::sub_0009B0A0()
{
    float t1;

    t1 = DAT_00384640;
    m_Field04 = m_Field00 * t1;
    m_Field0C = m_Field08 * t1;
}
