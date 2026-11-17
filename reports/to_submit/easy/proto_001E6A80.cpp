// bin: proto
// va: 0x001E6A80
// tool: the portal's starter code (no AI)
// sub_001E6A80 (0x001E6A80, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char sub_0007FFFF[];

class Class_001E6A80
{
public:
    int sub_001E6A80();
    char m_pad00[0x18];
    int m_Field18; // +0x18
};

int Class_001E6A80::sub_001E6A80()
{
    return (*(int*)(*(int*)m_Field18 + 32) & (int)sub_0007FFFF) == 64;
}
