// bin: xb
// va: 0x001942D0
// tool: the portal's starter code (no AI)
// sub_001942D0 (0x001942D0, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field68
{
    int sub_001C4560(int);
};

class Class_001942D0
{
public:
    void sub_001942D0(int a1, int a2);
    char m_pad00[0x68];
    Field68* m_Field68; // +0x68
    int m_Field6C; // +0x6C
    bool m_Field70; // +0x70
    bool m_Field71; // +0x71
    char m_pad72[0x2];
    int m_Field74; // +0x74
    int m_Field78; // +0x78
};

void Class_001942D0::sub_001942D0(int a1, int a2)
{
    if (m_Field71) {
        m_Field6C = m_Field68->sub_001C4560(m_Field6C);
        m_Field71 = false;
    }
    m_Field70 = true;
    m_Field71 = false;
    m_Field74 = a2;
    m_Field78 = a1;
}
