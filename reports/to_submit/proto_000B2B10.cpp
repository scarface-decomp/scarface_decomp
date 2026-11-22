// bin: proto
// va: 0x000B2B10
// what: 
// tool: the portal's starter code (no AI)

// sub_000B2B10 (Proto 0x000B2B10, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A968C;

class Class_000B2B10
{
public:
    Class_000B2B10* sub_000B2B10();
    float m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

Class_000B2B10* Class_000B2B10::sub_000B2B10()
{
    m_Field00 = DAT_003A968C;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = 0;
    return this;
}
