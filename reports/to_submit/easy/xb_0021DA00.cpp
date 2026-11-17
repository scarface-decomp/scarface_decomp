// bin: xb
// va: 0x0021DA00
// tool: the portal's starter code (no AI)
// sub_0021DA00 (0x0021DA00, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0021DA00
{
public:
    void sub_0021DA00(float a1);
    char m_pad00[0x3C];
    float m_Field3C; // +0x3C
};

void Class_0021DA00::sub_0021DA00(float a1)
{
    m_Field3C = a1 * a1;
}
