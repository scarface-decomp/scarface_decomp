// bin: xb
// va: 0x0029F460
// what: 
// tool: the portal's starter code (no AI)

// sub_0029F460 (0x0029F460, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

class Class_0029F460
{
public:
    int sub_0029F460(int a1);
    char m_pad00[0x84];
    int m_Field84; // +0x84
};

int Class_0029F460::sub_0029F460(int a1)
{
    m_Field84 = a1;
    return a1;
}
