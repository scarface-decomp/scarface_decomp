// bin: pc
// va: 0x006E9530
// tool: the portal's starter code (no AI)
// sub_006E9530 (0x006E9530, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006E9530
{
public:
    int sub_006E9530();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

int Class_006E9530::sub_006E9530()
{
    int t1, t2;

    t1 = m_Field04;
    if (m_Field04 >= 0) {
        t2 = m_Field00;
        if ((unsigned int)t1 >= (unsigned int)*(unsigned short*)(m_Field00 + 12)) goto L_18;
        return *(int*)(*(int*)(t2 + 4) + (t1 * 4));
    }
L_18:
    return 0;
}
