// bin: proto
// va: 0x00018780
// what: 
// tool: the portal's starter code (no AI)

// sub_00018780 (Proto 0x00018780, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00018780
{
public:
    unsigned short sub_00018780();
    int m_Field00; // +0x00
};

unsigned short Class_00018780::sub_00018780()
{
    return *(unsigned short*)(m_Field00 + 68);
}
