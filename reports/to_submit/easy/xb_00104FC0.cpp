// bin: xb
// va: 0x00104FC0
// tool: the portal's starter code (no AI)
// sub_00104FC0 (0x00104FC0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_00104FC0
{
public:
    int sub_00104FC0();
    char m_pad00[0x20];
    int m_Field20; // +0x20
};

int Class_00104FC0::sub_00104FC0()
{
    return sub_0002AC90(m_Field20);
}
