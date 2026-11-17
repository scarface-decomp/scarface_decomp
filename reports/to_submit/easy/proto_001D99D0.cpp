// bin: proto
// va: 0x001D99D0
// tool: the portal's starter code (no AI)
// sub_001D99D0 (0x001D99D0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_001D99D0
{
public:
    int sub_001D99D0();
    char m_pad00[0x63C];
    int m_Field63C; // +0x63C
};

int Class_001D99D0::sub_001D99D0()
{
    return sub_00028120(m_Field63C);
}
