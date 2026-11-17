// bin: xb
// va: 0x00281D40
// tool: the portal's starter code (no AI)
// sub_00281D40 (0x00281D40, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Field08
{
    void sub_002786C0(int);
};

class Class_00281D40
{
public:
    void sub_00281D40(int a1);
    char m_pad00[0x8];
    Field08* m_Field08; // +0x08
};

void Class_00281D40::sub_00281D40(int a1)
{
    m_Field08->sub_002786C0(a1);
}
