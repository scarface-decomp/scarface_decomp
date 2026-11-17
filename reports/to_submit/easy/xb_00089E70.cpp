// bin: xb
// va: 0x00089E70
// tool: the portal's starter code (no AI)
// sub_00089E70 (0x00089E70, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00089E70
{
public:
    void sub_00089E70(bool a1);
    void sub_00089BF0();
    char m_pad00[0x151];
    unsigned char m_Field151; // +0x151
};

void Class_00089E70::sub_00089E70(bool a1)
{
    unsigned char t1;

    t1 = m_Field151;
    if ((m_Field151 & 1) != (!a1)) {
        m_Field151 = (unsigned char)(((unsigned char)(((unsigned char)((!a1) ^ t1)) & 1)) ^ t1);
        sub_00089BF0();
    }
}
