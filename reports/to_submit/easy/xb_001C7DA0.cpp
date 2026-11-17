// bin: xb
// va: 0x001C7DA0
// tool: the portal's starter code (no AI)
// sub_001C7DA0 (0x001C7DA0, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00244450(int, int);

class Class_001C7DA0
{
public:
    void sub_001C7DA0(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

void Class_001C7DA0::sub_001C7DA0(int a1)
{
    int t1;

    if (a1) {
        t1 = sub_00244450(9, a1 * 4);
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
