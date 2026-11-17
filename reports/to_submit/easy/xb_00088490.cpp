// bin: xb
// va: 0x00088490
// tool: the portal's starter code (no AI)
// sub_00088490 (0x00088490, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_00088490
{
public:
    int sub_00088490();
    char m_pad00[0xB8];
    int m_FieldB8; // +0xB8
};

int Class_00088490::sub_00088490()
{
    return sub_0002AC90(m_FieldB8);
}
