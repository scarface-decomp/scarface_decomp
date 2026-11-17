// bin: pc
// va: 0x006E63E0
// tool: the portal's starter code (no AI)
// sub_006E63E0 (0x006E63E0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldD0
{
    void sub_006E8120();
};

class Class_006E63E0
{
public:
    void sub_006E63E0();
    char m_pad00[0xD0];
    FieldD0* m_FieldD0; // +0xD0
};

void Class_006E63E0::sub_006E63E0()
{
    m_FieldD0->sub_006E8120();
}
