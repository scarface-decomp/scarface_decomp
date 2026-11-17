// bin: xb
// va: 0x000AB320
// tool: the portal's starter code (no AI)
// sub_000AB320 (0x000AB320, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000AB320
{
public:
    int sub_000AB320();
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    char m_pad10[0x244];
    bool m_Field254; // +0x254
    char m_pad255[0xB];
    bool m_Field260; // +0x260
};

int Class_000AB320::sub_000AB320()
{
    int t1, t2;

    t1 = m_Field0C;
    if (m_Field0C) {
        t2 = *(int*)(t1 + 4);
        if (!*(int*)(t1 + 4)) goto L_2F;
        if (!*(int*)(t2 + 28)) goto L_2F;
        if (!m_Field254) goto L_2F;
        if (!m_Field260) goto L_2F;
        return 1;
    }
L_2F:
    return 0;
}
