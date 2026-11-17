// bin: xb
// va: 0x00242D30
// tool: the portal's starter code (no AI)
// sub_00242D30 (0x00242D30, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

class Class_00242D30
{
public:
    int sub_00242D30(int a1);
    int m_Field00; // +0x00
};

int Class_00242D30::sub_00242D30(int a1)
{
    return m_Field00 == *(int*)a1;
}
