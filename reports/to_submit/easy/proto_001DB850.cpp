// bin: proto
// va: 0x001DB850
// tool: the portal's starter code (no AI)
// sub_001DB850 (0x001DB850, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_0009FE50();
};

class Class_001DB850
{
public:
    bool sub_001DB850();
    char m_pad00[0x44];
    bool m_Field44; // +0x44
};

bool Class_001DB850::sub_001DB850()
{
    if (m_Field44) {
        return ((Object*)(int)this + 72)->sub_0009FE50();
    }
    return false;
}
