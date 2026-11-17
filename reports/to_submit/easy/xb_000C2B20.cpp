// bin: xb
// va: 0x000C2B20
// tool: the portal's starter code (no AI)
// sub_000C2B20 (0x000C2B20, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000C2B20
{
public:
    void sub_000C2B20();
    float m_Field00; // +0x00
    unsigned char m_Field04; // +0x04
};

void Class_000C2B20::sub_000C2B20()
{
    int t1;

    t1 = ((unsigned char)(m_Field04 & 208)) | 64;
    m_Field00 = 0.0f;
    m_Field04 = (unsigned char)t1;
}
