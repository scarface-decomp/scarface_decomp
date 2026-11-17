// bin: xb
// va: 0x000DC5F0
// tool: the portal's starter code (no AI)
// sub_000DC5F0 (0x000DC5F0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000DC5F0
{
public:
    int sub_000DC5F0();
    char m_pad00[0x20];
    int m_Field20; // +0x20
};

int Class_000DC5F0::sub_000DC5F0()
{
    return m_Field20 != 0;
}
