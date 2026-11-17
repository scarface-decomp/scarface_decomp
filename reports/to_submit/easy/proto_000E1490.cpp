// bin: proto
// va: 0x000E1490
// tool: the portal's starter code (no AI)
// sub_000E1490 (0x000E1490, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_000E1490
{
public:
    int sub_000E1490();
    char m_pad00[0x2E0];
    int m_Field2E0; // +0x2E0
};

int Class_000E1490::sub_000E1490()
{
    return sub_00028120(m_Field2E0);
}
