// bin: xb
// va: 0x00087500
// tool: the portal's starter code (no AI)
// sub_00087500 (0x00087500, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;

class Class_00087500
{
public:
    Class_00087500* sub_00087500();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
};

Class_00087500* Class_00087500::sub_00087500()
{
    float t1;

    t1 = DAT_0039D664;
    m_Field00 = t1;
    m_Field04 = t1;
    return this;
}
