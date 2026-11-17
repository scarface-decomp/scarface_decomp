// bin: xb
// va: 0x000D8750
// tool: the portal's starter code (no AI)
// sub_000D8750 (0x000D8750, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000D8750
{
public:
    void sub_000D8750(bool a1);
    char m_pad00[0x22C];
    unsigned char m_Field22C; // +0x22C
};

void Class_000D8750::sub_000D8750(bool a1)
{
    unsigned char t1;

    t1 = m_Field22C;
    if (((unsigned char)(m_Field22C >> 7)) != a1) {
        m_Field22C = (unsigned char)(((unsigned char)(t1 & 127)) | ((unsigned char)(a1 << 7)));
    }
}
