// bin: xb
// va: 0x001656E0
// tool: the portal's starter code (no AI)
// sub_001656E0 (0x001656E0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_001656E0
{
public:
    int sub_001656E0();
    char m_pad00[0x408];
    int m_Field408; // +0x408
};

int Class_001656E0::sub_001656E0()
{
    return sub_0002AC90(m_Field408) != 0;
}
