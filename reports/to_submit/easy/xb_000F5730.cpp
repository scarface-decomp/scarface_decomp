// bin: xb
// va: 0x000F5730
// tool: the portal's starter code (no AI)
// sub_000F5730 (0x000F5730, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00166CE0();
};

extern "C" int __cdecl sub_0002AC90(int);

class Class_000F5730
{
public:
    int sub_000F5730();
    char m_pad00[0x84];
    int m_Field84; // +0x84
};

int Class_000F5730::sub_000F5730()
{
    return ((Object*)sub_0002AC90(m_Field84))->sub_00166CE0() != 0;
}
