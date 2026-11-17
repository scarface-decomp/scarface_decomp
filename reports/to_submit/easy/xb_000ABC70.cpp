// bin: xb
// va: 0x000ABC70
// tool: the portal's starter code (no AI)
// sub_000ABC70 (0x000ABC70, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_000ABC70
{
public:
    int sub_000ABC70();
    char m_pad00[0x8];
    int m_Field08; // +0x08
};

int Class_000ABC70::sub_000ABC70()
{
    return sub_0002AC90(m_Field08);
}
