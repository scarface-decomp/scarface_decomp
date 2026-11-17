// bin: proto
// va: 0x000A0290
// tool: the portal's starter code (no AI)
// sub_000A0290 (0x000A0290, 82 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0009B800(int);
};

extern "C" int DAT_00462DD4;
extern "C" int __cdecl sub_00028120(int);

class Class_000A0290
{
public:
    void sub_000A0290(int a1);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    char m_pad10[0x174];
    int m_Field184; // +0x184
};

void Class_000A0290::sub_000A0290(int a1)
{
    int t4, t5, t6;

    if (sub_00028120(m_Field184)) {
        if (*(int*)(sub_00028120(m_Field184) + 16) != DAT_00462DD4) goto L_4E;
        t4 = m_Field0C;
        if (!m_Field0C) goto L_4E;
        t5 = *(int*)(t4 + 4);
        if (!*(int*)(t4 + 4)) goto L_4E;
        t6 = *(int*)(t5 + 20);
        if (!*(int*)(t5 + 20)) goto L_4E;
        ((Object*)t6)->sub_0009B800(a1);
        return;
    }
L_4E:
    ;
}
