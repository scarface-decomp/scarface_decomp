// bin: proto
// va: 0x001B8F50
// tool: the portal's starter code (no AI)
// sub_001B8F50 (0x001B8F50, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_001B8F50
{
public:
    int sub_001B8F50();
    char m_pad00[0x13C];
    int m_Field13C; // +0x13C
};

int Class_001B8F50::sub_001B8F50()
{
    return sub_00028120(m_Field13C);
}
