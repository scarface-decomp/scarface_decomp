// bin: proto
// va: 0x001D6820
// tool: the portal's starter code (no AI)
// sub_001D6820 (0x001D6820, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_001D6820
{
public:
    int sub_001D6820();
    char m_pad00[0xF4];
    int m_FieldF4; // +0xF4
};

int Class_001D6820::sub_001D6820()
{
    return sub_00028120(m_FieldF4);
}
