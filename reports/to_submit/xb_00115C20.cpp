// bin: xb
// va: 0x00115C20
// what: Increments the byte index at +0x65 and wraps it to 0 if it reaches the limit at +0x64.
// tool: Gemini 4 Neon

class Class_00115C20
{
public:
    void sub_00115C20();
    char m_pad00[0x64];
    unsigned char m_Field64; // +0x64
    unsigned char m_Field65; // +0x65
};

void Class_00115C20::sub_00115C20()
{
    m_Field65++;
    if (m_Field65 >= m_Field64) {
        m_Field65 = 0;
    }
}
