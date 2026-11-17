// bin: xb
// va: 0x000BCA90
// tool: the portal's starter code (no AI)
// sub_000BCA90 (0x000BCA90, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    int sub_000AB2A0();
};

struct Field118
{
    void sub_000BB380(int, int, int);
};

class Class_000BCA90
{
public:
    void sub_000BCA90(int a1);
    char m_pad00[0x4];
    Field04* m_Field04; // +0x04
    char m_pad08[0x83];
    unsigned char m_Field8B; // +0x8B
    char m_pad8C[0x8C];
    Field118 m_Field118; // +0x118
    char m_pad119[0x4B];
    int m_Field164; // +0x164
};

void Class_000BCA90::sub_000BCA90(int a1)
{
    int t1;

    if (m_Field8B & 2) {
        t1 = m_Field04->sub_000AB2A0();
        if (!t1) goto L_30;
        m_Field118.sub_000BB380(a1, t1, (int)(&m_Field164));
    }
L_30:
    ;
}
