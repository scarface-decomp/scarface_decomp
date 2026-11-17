// bin: proto
// va: 0x000B77A0
// tool: the portal's starter code (no AI)
// sub_000B77A0 (0x000B77A0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_000B77A0
{
public:
    int sub_000B77A0();
    char m_pad00[0x14];
    int m_Field14; // +0x14
};

int Class_000B77A0::sub_000B77A0()
{
    return sub_00028120(m_Field14);
}
