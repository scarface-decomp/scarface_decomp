// bin: xb
// va: 0x001522C0
// tool: the portal's starter code (no AI)
// sub_001522C0 (0x001522C0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;
extern "C" char DAT_003B3080[];

class Class_001522C0
{
public:
    Class_001522C0* sub_001522C0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

Class_001522C0* Class_001522C0::sub_001522C0()
{
    float t1;

    t1 = DAT_0039D664;
    m_Field00 = (int)DAT_003B3080;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = t1;
    return this;
}
