// bin: xb
// va: 0x0029F450
// what: 
// tool: the portal's starter code (no AI)

// sub_0029F450 (0x0029F450, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

class Class_0029F450
{
public:
    int sub_0029F450(int a1);
    char m_pad00[0x80];
    int m_Field80; // +0x80
};

int Class_0029F450::sub_0029F450(int a1)
{
    m_Field80 = a1;
    return a1;
}
