// bin: proto
// va: 0x0002CA00
// tool: the portal's starter code (no AI)
// sub_0002CA00 (0x0002CA00, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0002CA00
{
public:
    int sub_0002CA00(bool a1);
    char m_pad00[0x20];
    int m_Field20; // +0x20
    char m_pad24[0x6];
    unsigned short m_Field2A; // +0x2A
};

int Class_0002CA00::sub_0002CA00(bool a1)
{
    if ((unsigned int)((unsigned short)((unsigned char)a1)) < (unsigned int)m_Field2A) {
        return *(int*)((((unsigned char)a1) << 4) + m_Field20);
    }
    return 0;
}
