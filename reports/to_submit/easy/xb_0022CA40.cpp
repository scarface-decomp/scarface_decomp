// bin: xb
// va: 0x0022CA40
// tool: the portal's starter code (no AI)
// sub_0022CA40 (0x0022CA40, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field00
{
    bool sub_000C7230();
};

class Class_0022CA40
{
public:
    int sub_0022CA40();
    Field00* m_Field00; // +0x00
    char m_pad04[0x2D];
    bool m_Field31; // +0x31
    unsigned char m_Field32; // +0x32
};

int Class_0022CA40::sub_0022CA40()
{
    bool t1;

    t1 = m_Field00->sub_000C7230();
    m_Field32 = t1;
    if (!t1) {
        if (m_Field31) goto L_1C;
        return 0;
    }
L_1C:
    return 1;
}
