// bin: xb
// va: 0x000F5790
// tool: the portal's starter code (no AI)
// sub_000F5790 (0x000F5790, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_000F5790
{
public:
    int sub_000F5790();
    char m_pad00[0x224];
    int m_Field224; // +0x224
};

int Class_000F5790::sub_000F5790()
{
    return sub_0002AC90(m_Field224);
}
