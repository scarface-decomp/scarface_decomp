// bin: proto
// va: 0x001DB730
// tool: the portal's starter code (no AI)
// sub_001DB730 (0x001DB730, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_0009FE00(int);
};

class Class_001DB730
{
public:
    bool sub_001DB730(int a1);
    char m_pad00[0x44];
    bool m_Field44; // +0x44
};

bool Class_001DB730::sub_001DB730(int a1)
{
    if (m_Field44) {
        return ((Object*)(int)this + 72)->sub_0009FE00(a1);
    }
    return false;
}
