// bin: xb
// va: 0x000D8580
// tool: the portal's starter code (no AI)
// sub_000D8580 (0x000D8580, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field148
{
    void sub_00242D70(int);
};

struct Object
{
    bool sub_00164690();
};

extern "C" int DAT_00424EDC;

class Class_000D8580
{
public:
    void sub_000D8580(bool a1);
    char m_pad00[0x8];
    int m_Field08; // +0x08
    char m_pad0C[0x13C];
    Field148 m_Field148; // +0x148
    char m_pad149[0xB];
    int m_Field154; // +0x154
    char m_pad158[0x4];
    int m_Field15C; // +0x15C
    char m_pad160[0xCC];
    unsigned char m_Field22C; // +0x22C
};

void Class_000D8580::sub_000D8580(bool a1)
{
    int t1, t2, t5;

    t1 = m_Field08;
    if (m_Field08) {
        t2 = *(int*)(t1 + 80);
        if (!*(int*)(t1 + 80)) goto L_24;
        if (!((Object*)t2)->sub_00164690()) goto L_24;
        if (!a1) goto L_57;
    }
L_24:
    m_Field148.sub_00242D70(DAT_00424EDC);
    t5 = m_Field22C & 247;
    m_Field154 = 100;
    m_Field22C = (unsigned char)t5;
    m_Field15C = 0;
L_57:
    ;
}
