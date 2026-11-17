// bin: proto
// va: 0x001BB1A0
// tool: the portal's starter code (no AI)
// sub_001BB1A0 (0x001BB1A0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_001BB1A0
{
public:
    int sub_001BB1A0();
    char m_pad00[0xE0];
    int m_FieldE0; // +0xE0
};

int Class_001BB1A0::sub_001BB1A0()
{
    return sub_00028120(m_FieldE0);
}
