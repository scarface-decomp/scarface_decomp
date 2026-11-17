// bin: proto
// va: 0x000EEAA0
// tool: the portal's starter code (no AI)
// sub_000EEAA0 (0x000EEAA0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_000EEAA0
{
public:
    int sub_000EEAA0();
    char m_pad00[0x20];
    int m_Field20; // +0x20
};

int Class_000EEAA0::sub_000EEAA0()
{
    return sub_00028120(m_Field20);
}
