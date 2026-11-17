// bin: xb
// va: 0x00277C90
// tool: the portal's starter code (no AI)
// sub_00277C90 (0x00277C90, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Field58
{
    void sub_00292DF0(int);
};

class Class_00277C90
{
public:
    void sub_00277C90(int a1);
    char m_pad00[0x58];
    Field58* m_Field58; // +0x58
};

void Class_00277C90::sub_00277C90(int a1)
{
    m_Field58->sub_00292DF0(a1);
}
