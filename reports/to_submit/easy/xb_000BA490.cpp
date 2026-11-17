// bin: xb
// va: 0x000BA490
// tool: the portal's starter code (no AI)
// sub_000BA490 (0x000BA490, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;

class Class_000BA490
{
public:
    Class_000BA490* sub_000BA490();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
};

Class_000BA490* Class_000BA490::sub_000BA490()
{
    float t1;

    t1 = DAT_0039D65C;
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field08 = t1;
    return this;
}
