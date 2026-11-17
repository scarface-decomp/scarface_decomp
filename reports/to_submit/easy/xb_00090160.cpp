// bin: xb
// va: 0x00090160
// tool: the portal's starter code (no AI)
// sub_00090160 (0x00090160, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00027590(int);

class Class_00090160
{
public:
    void sub_00090160(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

void Class_00090160::sub_00090160(int a1)
{
    int t1;

    if (a1) {
        t1 = sub_00027590(a1 * 4);
        m_Field00 = t1;
        if (!t1) goto L_35;
        m_Field08 = (a1 * 4) + t1;
        m_Field04 = t1;
        return;
    }
    m_Field00 = 0;
L_35:
    m_Field04 = 0;
    m_Field08 = 0;
}
