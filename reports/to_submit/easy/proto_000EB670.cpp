// bin: proto
// va: 0x000EB670
// tool: the portal's starter code (no AI)
// sub_000EB670 (0x000EB670, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_000EB670
{
public:
    int sub_000EB670();
    char m_pad00[0x18];
    int m_Field18; // +0x18
};

int Class_000EB670::sub_000EB670()
{
    return sub_00028120(m_Field18);
}
