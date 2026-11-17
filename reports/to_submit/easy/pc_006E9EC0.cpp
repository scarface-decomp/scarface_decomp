// bin: pc
// va: 0x006E9EC0
// tool: the portal's starter code (no AI)
// sub_006E9EC0 (0x006E9EC0, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0043CE00(int);

class Class_006E9EC0
{
public:
    bool sub_006E9EC0(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

bool Class_006E9EC0::sub_006E9EC0(int a1)
{
    int t1;

    if (a1) {
        t1 = sub_0043CE00(a1 * 8);
        m_Field00 = t1;
        if (!t1) goto L_48;
        m_Field0C = (a1 * 8) + t1;
        m_Field04 = t1;
        m_Field08 = t1;
        return true;
    }
    m_Field00 = 0;
    m_Field08 = 0;
    m_Field0C = 0;
L_48:
    m_Field04 = 0;
    return false;
}
