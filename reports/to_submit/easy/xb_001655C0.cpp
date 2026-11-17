// bin: xb
// va: 0x001655C0
// tool: the portal's starter code (no AI)
// sub_001655C0 (0x001655C0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_001655C0
{
public:
    int sub_001655C0();
    char m_pad00[0xE8];
    int m_FieldE8; // +0xE8
};

int Class_001655C0::sub_001655C0()
{
    return sub_0002AC90(m_FieldE8);
}
