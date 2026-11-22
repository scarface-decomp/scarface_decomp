// bin: pc
// va: 0x006EBBD0
// what: 
// tool: the portal's starter code (no AI)

// sub_006EBBD0 (PC 0x006EBBD0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field00
{
    void sub_006EB750();
};

class Class_006EBBD0
{
public:
    void sub_006EBBD0();
    Field00* m_Field00; // +0x00
    unsigned short m_Field04; // +0x04
};

void Class_006EBBD0::sub_006EBBD0()
{
    if (m_Field04 == 2) {
        m_Field00->sub_006EB750();
        return;
    }
}
