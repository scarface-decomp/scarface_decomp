// bin: pc
// va: 0x006F4FC0
// what: 
// tool: the portal's starter code (no AI)

// sub_006F4FC0 (PC 0x006F4FC0, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char sub_00652580[];
extern "C" char sub_006EF980[];
extern "C" char sub_006F4E80[];
extern "C" char sub_006F4ED0[];

class Class_006F4FC0
{
public:
    Class_006F4FC0* sub_006F4FC0(int a1, int a2);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

Class_006F4FC0* Class_006F4FC0::sub_006F4FC0(int a1, int a2)
{
    m_Field10 = 0;
    m_Field14 = a2;
    m_Field18 = a1;
    m_Field00 = (int)sub_006F4E80;
    m_Field04 = (int)sub_006F4ED0;
    m_Field08 = (int)sub_00652580;
    m_Field0C = (int)sub_006EF980;
    return this;
}
