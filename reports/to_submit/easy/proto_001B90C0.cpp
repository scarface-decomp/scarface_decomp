// bin: proto
// va: 0x001B90C0
// tool: the portal's starter code (no AI)
// sub_001B90C0 (0x001B90C0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_001B90C0
{
public:
    int sub_001B90C0();
    char m_pad00[0x140];
    int m_Field140; // +0x140
};

int Class_001B90C0::sub_001B90C0()
{
    return sub_00028120(m_Field140);
}
