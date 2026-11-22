// bin: proto
// va: 0x000CA720
// what: 
// tool: the portal's starter code (no AI)

// sub_000CA720 (Proto 0x000CA720, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000CA720
{
public:
    float sub_000CA720();
    char m_pad00[0x20];
    int m_Field20; // +0x20
};

float Class_000CA720::sub_000CA720()
{
    return *(float*)((int)this + ((m_Field20 + 3 + ((m_Field20 + 3) * 2)) * 4));
}
