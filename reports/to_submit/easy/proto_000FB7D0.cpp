// bin: proto
// va: 0x000FB7D0
// tool: the portal's starter code (no AI)
// sub_000FB7D0 (0x000FB7D0, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_002018F0(int, int);

class Class_000FB7D0
{
public:
    void sub_000FB7D0(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

void Class_000FB7D0::sub_000FB7D0(int a1)
{
    int t1;

    if (a1) {
        t1 = sub_002018F0(10, a1 * 4);
        m_Field00 = t1;
        if (!t1) goto L_37;
        m_Field08 = (a1 * 4) + t1;
        m_Field04 = t1;
        return;
    }
    m_Field00 = 0;
L_37:
    m_Field04 = 0;
    m_Field08 = 0;
}
