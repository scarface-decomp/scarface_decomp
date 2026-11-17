// bin: xb
// va: 0x000F2AF0
// tool: the portal's starter code (no AI)
// sub_000F2AF0 (0x000F2AF0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_000F2AF0
{
public:
    int sub_000F2AF0();
    char m_pad00[0x250];
    int m_Field250; // +0x250
};

int Class_000F2AF0::sub_000F2AF0()
{
    return sub_0002AC90(m_Field250);
}
