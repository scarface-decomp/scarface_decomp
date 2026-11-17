// bin: xb
// va: 0x000C4290
// tool: the portal's starter code (no AI)
// sub_000C4290 (0x000C4290, 84 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    void sub_000C40B0();
};

extern "C" int __cdecl sub_0002AC90(int);

class Class_000C4290
{
public:
    void sub_000C4290(int a1);
    void sub_000C3B10(int, int);
    void sub_000C4110(int, int, int);
    int m_Field00; // +0x00
    Field04* m_Field04; // +0x04
    int m_Field08; // +0x08
};

void Class_000C4290::sub_000C4290(int a1)
{
    Field04* t1;
    int t3, t4;

    t1 = m_Field04;
    if (!m_Field04) goto L_50;
    if (!m_Field08) goto L_50;
    if (!m_Field00) goto L_50;
    t3 = *(int*)((int)t1 + 8);
    t4 = sub_0002AC90(*(int*)((int)t1 + 4));
    if (t3) {
        if (!t4) goto L_4F;
        sub_000C4110(a1, t3, t4);
        sub_000C3B10(a1, t3);
        m_Field04->sub_000C40B0();
    }
L_4F:
L_50:
    ;
}
