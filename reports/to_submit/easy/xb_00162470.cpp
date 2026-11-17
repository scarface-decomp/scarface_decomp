// bin: xb
// va: 0x00162470
// tool: the portal's starter code (no AI)
// sub_00162470 (0x00162470, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00162470
{
public:
    Class_00162470* sub_00162470(bool a1, bool a2, float a3);
    unsigned char m_Field00; // +0x00
    char m_pad01[0x3];
    float m_Field04; // +0x04
};

Class_00162470* Class_00162470::sub_00162470(bool a1, bool a2, float a3)
{
    m_Field00 = (unsigned char)(((unsigned char)(a1 << 2)) + a2);
    m_Field04 = a3;
    return this;
}
