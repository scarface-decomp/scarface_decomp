// bin: proto
// va: 0x00086780
// what: 
// tool: the portal's starter code (no AI)

// sub_00086780 (Proto 0x00086780, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00025160(int);

class Class_00086780
{
public:
    int sub_00086780();
    char m_pad00[0x14];
    int m_Field14; // +0x14
    unsigned short m_Field18; // +0x18
};

int Class_00086780::sub_00086780()
{
    if ((unsigned int)m_Field18 > (unsigned int)1) {
        sub_00025160(m_Field14);
    }
    m_Field14 = 0;
    m_Field18 = 0;
    return 0;
}
