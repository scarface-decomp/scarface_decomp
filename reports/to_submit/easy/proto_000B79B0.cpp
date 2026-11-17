// bin: proto
// va: 0x000B79B0
// tool: the portal's starter code (no AI)
// sub_000B79B0 (0x000B79B0, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00015510(int);

class Class_000B79B0
{
public:
    void sub_000B79B0();
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    char m_pad10[0x18];
    bool m_Field28; // +0x28
};

void Class_000B79B0::sub_000B79B0()
{
    int t1;

    if (!m_Field28) goto L_2A;
    t1 = m_Field0C;
    if (m_Field0C) {
        if (!*(unsigned char*)t1) goto L_1F;
        sub_00015510(t1);
    }
L_1F:
    m_Field0C = 0;
    m_Field28 = false;
L_2A:
    ;
}
