// bin: xb
// va: 0x001F2980
// tool: the portal's starter code (no AI)
// sub_001F2980 (0x001F2980, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_001F2980
{
public:
    int sub_001F2980();
    char m_pad00[0x134];
    int m_Field134; // +0x134
};

int Class_001F2980::sub_001F2980()
{
    return sub_0002AC90(m_Field134);
}
