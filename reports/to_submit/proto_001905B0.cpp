// bin: proto
// va: 0x001905B0
// what: 
// tool: the portal's starter code (no AI)

// sub_001905B0 (Proto 0x001905B0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field4C
{
    void sub_000590D0();
};

class Class_001905B0
{
public:
    void sub_001905B0();
    char m_pad00[0x4C];
    Field4C* m_Field4C; // +0x4C
};

void Class_001905B0::sub_001905B0()
{
    m_Field4C->sub_000590D0();
}
