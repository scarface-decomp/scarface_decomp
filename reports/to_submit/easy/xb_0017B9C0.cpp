// bin: xb
// va: 0x0017B9C0
// tool: the portal's starter code (no AI)
// sub_0017B9C0 (0x0017B9C0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_0017B9C0
{
public:
    int sub_0017B9C0();
    char m_pad00[0x4];
    int m_Field04; // +0x04
};

int Class_0017B9C0::sub_0017B9C0()
{
    return sub_0002AC90(m_Field04);
}
