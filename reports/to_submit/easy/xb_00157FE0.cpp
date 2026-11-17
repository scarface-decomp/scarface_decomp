// bin: xb
// va: 0x00157FE0
// tool: the portal's starter code (no AI)
// sub_00157FE0 (0x00157FE0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_00157FE0
{
public:
    int sub_00157FE0();
    int m_Field00; // +0x00
};

int Class_00157FE0::sub_00157FE0()
{
    return !sub_0002AC90(m_Field00);
}
