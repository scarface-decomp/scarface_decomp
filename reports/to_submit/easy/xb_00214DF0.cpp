// bin: xb
// va: 0x00214DF0
// tool: the portal's starter code (no AI)
// sub_00214DF0 (0x00214DF0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_00214DF0
{
public:
    int sub_00214DF0();
    char m_pad00[0x65C];
    int m_Field65C; // +0x65C
};

int Class_00214DF0::sub_00214DF0()
{
    return sub_0002AC90(m_Field65C);
}
