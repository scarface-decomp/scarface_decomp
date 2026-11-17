// bin: xb
// va: 0x000C5520
// tool: the portal's starter code (no AI)
// sub_000C5520 (0x000C5520, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00014BE0(int);

class Class_000C5520
{
public:
    void sub_000C5520();
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    char m_pad10[0x18];
    bool m_Field28; // +0x28
};

void Class_000C5520::sub_000C5520()
{
    int t1;

    if (!m_Field28) goto L_2A;
    t1 = m_Field0C;
    if (m_Field0C) {
        if (!*(unsigned char*)t1) goto L_1F;
        sub_00014BE0(t1);
    }
L_1F:
    m_Field0C = 0;
    m_Field28 = false;
L_2A:
    ;
}
