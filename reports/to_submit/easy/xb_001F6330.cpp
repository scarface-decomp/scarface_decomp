// bin: xb
// va: 0x001F6330
// tool: the portal's starter code (no AI)
// sub_001F6330 (0x001F6330, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_001F6330
{
public:
    int sub_001F6330();
    char m_pad00[0xE0];
    int m_FieldE0; // +0xE0
};

int Class_001F6330::sub_001F6330()
{
    return sub_0002AC90(m_FieldE0) != 0;
}
