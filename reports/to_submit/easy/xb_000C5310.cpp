// bin: xb
// va: 0x000C5310
// tool: the portal's starter code (no AI)
// sub_000C5310 (0x000C5310, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_000C5310
{
public:
    int sub_000C5310();
    char m_pad00[0x14];
    int m_Field14; // +0x14
};

int Class_000C5310::sub_000C5310()
{
    return sub_0002AC90(m_Field14);
}
