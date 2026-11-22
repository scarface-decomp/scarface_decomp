// bin: pc
// va: 0x006EB6A0
// what: 
// tool: the portal's starter code (no AI)

// sub_006EB6A0 (PC 0x006EB6A0, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F6398;

class Class_006EB6A0
{
public:
    Class_006EB6A0* sub_006EB6A0();
    int m_Field00; // +0x00
    unsigned short m_Field04; // +0x04
    char m_pad06[0x2];
    unsigned short m_Field08; // +0x08
};

Class_006EB6A0* Class_006EB6A0::sub_006EB6A0()
{
    m_Field00 = DAT_007F6398;
    *(unsigned short*)(DAT_007F6398 + -4) += 1;
    m_Field08 = 0;
    m_Field04 = 2;
    return this;
}
