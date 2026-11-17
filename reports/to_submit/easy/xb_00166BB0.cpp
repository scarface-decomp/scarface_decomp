// bin: xb
// va: 0x00166BB0
// tool: the portal's starter code (no AI)
// sub_00166BB0 (0x00166BB0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_00166BB0
{
public:
    int sub_00166BB0();
    char m_pad00[0x154];
    int m_Field154; // +0x154
};

int Class_00166BB0::sub_00166BB0()
{
    return sub_0002AC90(m_Field154);
}
