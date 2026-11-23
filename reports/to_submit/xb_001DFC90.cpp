// bin: xb
// va: 0x001DFC90
// what: 
// tool: the portal's starter code (no AI)

// sub_001DFC90 (0x001DFC90, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001DFC90
{
public:
    bool sub_001DFC90();
    char m_pad00[0x60];
    unsigned char : 3;
    unsigned char m_Field60_bit3 : 1; // +0x60, bit 3
};

bool Class_001DFC90::sub_001DFC90()
{
    return m_Field60_bit3;
}
