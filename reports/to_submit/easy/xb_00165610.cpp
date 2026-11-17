// bin: xb
// va: 0x00165610
// tool: the portal's starter code (no AI)
// sub_00165610 (0x00165610, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_00165610
{
public:
    int sub_00165610();
    char m_pad00[0xE4];
    int m_FieldE4; // +0xE4
};

int Class_00165610::sub_00165610()
{
    return sub_0002AC90(m_FieldE4);
}
