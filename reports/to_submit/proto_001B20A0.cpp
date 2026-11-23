// bin: proto
// va: 0x001B20A0
// what: 
// tool: the portal's starter code (no AI)

// sub_001B20A0 (Proto 0x001B20A0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001B1FA0(void);

class Class_001B20A0
{
public:
    void sub_001B20A0();
    char m_pad00[0x44];
    unsigned short m_Field44; // +0x44
    char m_pad46[0x4];
    unsigned short m_Field4A; // +0x4A
};

void Class_001B20A0::sub_001B20A0()
{
    m_Field44 = 0;
    m_Field4A = 0;
    sub_001B1FA0();
}
