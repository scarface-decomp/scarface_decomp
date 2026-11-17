// bin: proto
// va: 0x0017F7A0
// tool: the portal's starter code (no AI)
// sub_0017F7A0 (0x0017F7A0, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_002018F0(int, int);

class Class_0017F7A0
{
public:
    void sub_0017F7A0(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

void Class_0017F7A0::sub_0017F7A0(int a1)
{
    int t1;

    if (a1) {
        t1 = sub_002018F0(7, (a1 + (a1 * 2)) << 2);
        m_Field00 = t1;
        if (!t1) goto L_36;
        m_Field08 = ((a1 + (a1 * 2)) << 2) + t1;
        m_Field04 = t1;
        return;
    }
    m_Field00 = 0;
L_36:
    m_Field04 = 0;
    m_Field08 = 0;
}
