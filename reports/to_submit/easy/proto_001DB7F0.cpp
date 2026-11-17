// bin: proto
// va: 0x001DB7F0
// tool: the portal's starter code (no AI)
// sub_001DB7F0 (0x001DB7F0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0009F2F0(int);
};

class Class_001DB7F0
{
public:
    void sub_001DB7F0(int a1);
    char m_pad00[0x44];
    bool m_Field44; // +0x44
};

void Class_001DB7F0::sub_001DB7F0(int a1)
{
    if (m_Field44) {
        ((Object*)(int)this + 72)->sub_0009F2F0(a1);
        return;
    }
}
