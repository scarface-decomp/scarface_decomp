// bin: xb
// va: 0x00091F10
// tool: the portal's starter code (no AI)
// sub_00091F10 (0x00091F10, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00091F10
{
public:
    void sub_00091F10();
    int m_Field00; // +0x00
    char m_pad04[0x20];
    unsigned char m_Field24; // +0x24
};

void Class_00091F10::sub_00091F10()
{
    unsigned char t1;

    if (m_Field00) {
        t1 = m_Field24;
        if (!(m_Field24 & 2)) goto L_17;
        m_Field00 = 0;
        m_Field24 = (unsigned char)(t1 & 253);
    }
L_17:
    ;
}
