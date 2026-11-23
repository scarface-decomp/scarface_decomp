// bin: xb
// va: 0x001EBC10
// what: 
// tool: the portal's starter code (no AI)

// sub_001EBC10 (0x001EBC10, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001EBC10
{
public:
    bool sub_001EBC10();
    char m_pad00[0x58];
    unsigned char : 1;
    unsigned char m_Field58_bit1 : 1; // +0x58, bit 1
};

bool Class_001EBC10::sub_001EBC10()
{
    return m_Field58_bit1;
}
