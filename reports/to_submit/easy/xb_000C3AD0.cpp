// bin: xb
// va: 0x000C3AD0
// tool: the portal's starter code (no AI)
// sub_000C3AD0 (0x000C3AD0, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    void sub_000C3A50(int);
};

extern "C" float DAT_0039D65C;

class Class_000C3AD0
{
public:
    int sub_000C3AD0(int a1, int a2);
    char m_pad00[0x4];
    Field04* m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x4];
    float m_Field10; // +0x10
    float m_Field14; // +0x14
};

int Class_000C3AD0::sub_000C3AD0(int a1, int a2)
{
    int r_eax;

    if (m_Field04) {
        r_eax = a1;
        m_Field04->sub_000C3A50(a1);
    }
    r_eax = a2;
    m_Field08 = a2;
    if (!a2) {
        m_Field10 = DAT_0039D65C;
        m_Field14 = 0.0f;
    }
    return r_eax;
}
