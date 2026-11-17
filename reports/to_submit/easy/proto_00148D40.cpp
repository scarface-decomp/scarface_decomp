// bin: proto
// va: 0x00148D40
// tool: the portal's starter code (no AI)
// sub_00148D40 (0x00148D40, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_00148D40
{
public:
    int sub_00148D40();
    char m_pad00[0xD8];
    int m_FieldD8; // +0xD8
};

int Class_00148D40::sub_00148D40()
{
    return sub_00028120(m_FieldD8);
}
