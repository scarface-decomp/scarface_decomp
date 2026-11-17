// bin: xb
// va: 0x001C2BD0
// tool: the portal's starter code (no AI)
// sub_001C2BD0 (0x001C2BD0, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039E148;

class Class_001C2BD0
{
public:
    void sub_001C2BD0(int a1);
    char m_pad00[0x60];
    unsigned char m_Field60; // +0x60
    char m_pad61[0x2F];
    float m_Field90; // +0x90
    char m_pad94[0x4];
    int m_Field98; // +0x98
};

void Class_001C2BD0::sub_001C2BD0(int a1)
{
    float t1;
    int t2;

    if (a1 != m_Field98) {
        t1 = DAT_0039E148;
        m_Field98 = a1;
        t2 = m_Field60 | 1;
        m_Field90 = t1;
        m_Field60 = (unsigned char)t2;
    }
}
