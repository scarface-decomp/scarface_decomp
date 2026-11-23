// bin: xb
// va: 0x001C5A40
// what: 
// tool: the portal's starter code (no AI)

// sub_001C5A40 (0x001C5A40, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field4C
{
    void sub_00022720();
};

class Class_001C5A40
{
public:
    void sub_001C5A40();
    char m_pad00[0x4C];
    Field4C* m_Field4C; // +0x4C
};

void Class_001C5A40::sub_001C5A40()
{
    m_Field4C->sub_00022720();
}
