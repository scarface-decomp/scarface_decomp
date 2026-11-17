// bin: pc
// va: 0x006E9550
// tool: the portal's starter code (no AI)
// sub_006E9550 (0x006E9550, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006E9550
{
public:
    Class_006E9550* sub_006E9550(int a1, int a2, int a3);
    void sub_006E91B0(int);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    unsigned short m_Field0C; // +0x0C
    unsigned short m_Field0E; // +0x0E
    unsigned short m_Field10; // +0x10
    unsigned short m_Field12; // +0x12
    unsigned short m_Field14; // +0x14
    unsigned char m_Field16; // +0x16
};

Class_006E9550* Class_006E9550::sub_006E9550(int a1, int a2, int a3)
{
    m_Field16 &= 254;
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = (unsigned short)a1;
    m_Field0E = 0;
    m_Field10 = 0;
    m_Field12 = (unsigned short)a3;
    m_Field14 = (unsigned short)a2;
    sub_006E91B0((unsigned short)((unsigned short)a1));
    return this;
}
