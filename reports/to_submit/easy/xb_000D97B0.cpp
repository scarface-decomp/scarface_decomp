// bin: xb
// va: 0x000D97B0
// tool: the portal's starter code (no AI)
// sub_000D97B0 (0x000D97B0, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field228
{
    bool sub_000DE420(int);
};

class Class_000D97B0
{
public:
    void sub_000D97B0(int a1);
    void sub_000D9780();
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    char m_pad10[0x218];
    Field228* m_Field228; // +0x228
    char m_pad22C[0x2];
    unsigned char m_Field22E; // +0x22E
};

void Class_000D97B0::sub_000D97B0(int a1)
{
    if (m_Field22E & 1) {
        if (!m_Field0C) goto L_32;
        if (!m_Field228) goto L_32;
        if (m_Field228->sub_000DE420(a1)) goto L_32;
        sub_000D9780();
    }
L_32:
    ;
}
