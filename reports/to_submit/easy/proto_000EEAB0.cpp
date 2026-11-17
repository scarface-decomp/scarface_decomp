// bin: proto
// va: 0x000EEAB0
// tool: the portal's starter code (no AI)
// sub_000EEAB0 (0x000EEAB0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_000EEAB0
{
public:
    int sub_000EEAB0();
    char m_pad00[0x24];
    int m_Field24; // +0x24
};

int Class_000EEAB0::sub_000EEAB0()
{
    return sub_00028120(m_Field24);
}
