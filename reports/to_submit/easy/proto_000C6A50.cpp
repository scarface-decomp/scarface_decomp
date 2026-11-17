// bin: proto
// va: 0x000C6A50
// tool: the portal's starter code (no AI)
// sub_000C6A50 (0x000C6A50, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field154
{
    void sub_00200290(int);
};

struct Object
{
    bool sub_00148210();
};

extern "C" int DAT_003FFA88;

class Class_000C6A50
{
public:
    void sub_000C6A50(bool a1);
    char m_pad00[0x8];
    int m_Field08; // +0x08
    char m_pad0C[0x148];
    Field154 m_Field154; // +0x154
    char m_pad155[0xB];
    int m_Field160; // +0x160
    char m_pad164[0x4];
    int m_Field168; // +0x168
    char m_pad16C[0xCA];
    unsigned char m_Field236; // +0x236
};

void Class_000C6A50::sub_000C6A50(bool a1)
{
    int t1, t2, t5;

    t1 = m_Field08;
    if (m_Field08) {
        t2 = *(int*)(t1 + 80);
        if (!*(int*)(t1 + 80)) goto L_24;
        if (!((Object*)t2)->sub_00148210()) goto L_24;
        if (!a1) goto L_57;
    }
L_24:
    m_Field154.sub_00200290(DAT_003FFA88);
    t5 = m_Field236 & 247;
    m_Field160 = 100;
    m_Field236 = (unsigned char)t5;
    m_Field168 = 0;
L_57:
    ;
}
