// bin: xb
// va: 0x000BCB00
// tool: the portal's starter code (no AI)
// sub_000BCB00 (0x000BCB00, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000AB100();
};

class Class_000BCB00
{
public:
    void sub_000BCB00(int a1, int a2, int a3);
    char m_pad00[0x4];
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x4];
    int m_Field10; // +0x10
    char m_pad14[0x50];
    int m_Field64; // +0x64
    int m_Field68; // +0x68
    int m_Field6C; // +0x6C
};

void Class_000BCB00::sub_000BCB00(int a1, int a2, int a3)
{
    int t1, t2, t3;

    m_Field04 = a1;
    m_Field08 = a2;
    m_Field10 = a3;
    if (a1) {
        t1 = ((Object*)a1)->sub_000AB100();
        if (!t1) goto L_4E;
        t2 = *(int*)(t1 + 8);
        if (!*(int*)(t1 + 8)) goto L_4E;
        if (a3 < 0) goto L_4E;
        t3 = *(int*)(t2 + 24) + (a3 << 6) + 48;
        m_Field64 = *(int*)(*(int*)(t2 + 24) + (a3 << 6) + 48);
        m_Field68 = *(int*)(t3 + 4);
        m_Field6C = *(int*)(t3 + 8);
    }
L_4E:
    ;
}
