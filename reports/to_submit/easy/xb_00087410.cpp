// bin: xb
// va: 0x00087410
// tool: the portal's starter code (no AI)
// sub_00087410 (0x00087410, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;

class Class_00087410
{
public:
    Class_00087410* sub_00087410();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

Class_00087410* Class_00087410::sub_00087410()
{
    float t1;

    t1 = DAT_0039D664;
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = t1;
    return this;
}
