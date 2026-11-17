// bin: xb
// va: 0x000BF980
// tool: the portal's starter code (no AI)
// sub_000BF980 (0x000BF980, 82 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_000C2380();
};

extern "C" float DAT_0039DD50;

class Class_000BF980
{
public:
    void sub_000BF980(int a1);
    void sub_000BD1F0(int);
    void sub_000BE4B0(float, int);
    char m_pad00[0x8];
    Field08* m_Field08; // +0x08
    char m_pad0C[0x7F];
    unsigned char m_Field8B; // +0x8B
    char m_pad8C[0x50];
    float m_FieldDC; // +0xDC
};

void Class_000BF980::sub_000BF980(int a1)
{
    int t2;

    if (m_Field08) {
        if (m_Field8B & 2) goto L_4E;
        t2 = m_Field08->sub_000C2380();
        if (!t2) goto L_4E;
        sub_000BE4B0(m_FieldDC * *(float*)t2 * DAT_0039DD50, t2);
        if (!a1) goto L_4E;
        sub_000BD1F0(a1);
    }
L_4E:
    ;
}
