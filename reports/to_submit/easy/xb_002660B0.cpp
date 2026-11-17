// bin: xb
// va: 0x002660B0
// tool: the portal's starter code (no AI)
// sub_002660B0 (0x002660B0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Field2D4
{
    void sub_0029BAC0(int);
};

class Class_002660B0
{
public:
    void sub_002660B0(int a1);
    char m_pad00[0x2D4];
    Field2D4* m_Field2D4; // +0x2D4
};

void Class_002660B0::sub_002660B0(int a1)
{
    m_Field2D4->sub_0029BAC0(a1);
}
