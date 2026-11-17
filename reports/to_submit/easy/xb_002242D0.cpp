// bin: xb
// va: 0x002242D0
// tool: the portal's starter code (no AI)
// sub_002242D0 (0x002242D0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char sub_0007FFFF[];

class Class_002242D0
{
public:
    int sub_002242D0();
    char m_pad00[0x18];
    int m_Field18; // +0x18
};

int Class_002242D0::sub_002242D0()
{
    return (*(int*)(*(int*)m_Field18 + 32) & (int)sub_0007FFFF) == 64;
}
