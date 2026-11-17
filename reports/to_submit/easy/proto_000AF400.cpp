// bin: proto
// va: 0x000AF400
// tool: the portal's starter code (no AI)
// sub_000AF400 (0x000AF400, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0009F0A0();
};

class Class_000AF400
{
public:
    void sub_000AF400(int a1, int a2, int a3);
    char m_pad00[0x4];
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x4];
    int m_Field10; // +0x10
    char m_pad14[0x58];
    int m_Field6C; // +0x6C
    int m_Field70; // +0x70
    int m_Field74; // +0x74
};

void Class_000AF400::sub_000AF400(int a1, int a2, int a3)
{
    int t1, t2, t3;

    m_Field04 = a1;
    m_Field08 = a2;
    m_Field10 = a3;
    if (a1) {
        t1 = ((Object*)a1)->sub_0009F0A0();
        if (!t1) goto L_4E;
        t2 = *(int*)(t1 + 8);
        if (!*(int*)(t1 + 8)) goto L_4E;
        if (a3 < 0) goto L_4E;
        t3 = *(int*)(t2 + 24) + (a3 << 6) + 48;
        m_Field6C = *(int*)(*(int*)(t2 + 24) + (a3 << 6) + 48);
        m_Field70 = *(int*)(t3 + 4);
        m_Field74 = *(int*)(t3 + 8);
    }
L_4E:
    ;
}
