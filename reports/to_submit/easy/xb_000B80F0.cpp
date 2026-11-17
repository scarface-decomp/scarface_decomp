// bin: xb
// va: 0x000B80F0
// tool: the portal's starter code (no AI)
// sub_000B80F0 (0x000B80F0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;
extern "C" float DAT_003A50BC;

class Class_000B80F0
{
public:
    void sub_000B80F0();
    float m_Field00; // +0x00
    bool m_Field04; // +0x04
    char m_pad05[0x3];
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

void Class_000B80F0::sub_000B80F0()
{
    float t2;

    m_Field00 = DAT_003A50BC;
    m_Field08 = 0.0f;
    m_Field0C = 0.0f;
    t2 = DAT_0039D664;
    m_Field04 = false;
    m_Field10 = t2;
}
