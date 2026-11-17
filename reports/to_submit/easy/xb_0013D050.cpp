// bin: xb
// va: 0x0013D050
// tool: the portal's starter code (no AI)
// sub_0013D050 (0x0013D050, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_0013D050
{
public:
    int sub_0013D050();
    char m_pad00[0xCC];
    int m_FieldCC; // +0xCC
};

int Class_0013D050::sub_0013D050()
{
    return sub_0002AC90(m_FieldCC) != 0;
}
