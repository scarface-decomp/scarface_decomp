// bin: xb
// va: 0x000878B0
// tool: the portal's starter code (no AI)
// sub_000878B0 (0x000878B0, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000878B0
{
public:
    void sub_000878B0();
    bool m_Field00; // +0x00
    char m_pad01[0x7];
    int m_Field08; // +0x08
    char m_pad0C[0x4];
    int m_Field10; // +0x10
    char m_pad14[0xC];
    unsigned short m_Field20; // +0x20
};

void Class_000878B0::sub_000878B0()
{
    int t1;

    if (!m_Field00) goto L_21;
    t1 = m_Field08;
    if (m_Field08) {
        if (!*(unsigned char*)t1) goto L_19;
        m_Field10 = 0;
        m_Field08 = 0;
    }
L_19:
    m_Field20 = 65535;
    m_Field00 = false;
L_21:
    ;
}
