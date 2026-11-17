// bin: xb
// va: 0x002172E0
// tool: the portal's starter code (no AI)
// sub_002172E0 (0x002172E0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000AB450(int);
};

class Class_002172E0
{
public:
    void sub_002172E0(int a1);
    char m_pad00[0x44];
    bool m_Field44; // +0x44
};

void Class_002172E0::sub_002172E0(int a1)
{
    if (m_Field44) {
        ((Object*)(int)this + 72)->sub_000AB450(a1);
        return;
    }
}
