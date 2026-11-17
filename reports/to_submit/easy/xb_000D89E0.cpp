// bin: xb
// va: 0x000D89E0
// tool: the portal's starter code (no AI)
// sub_000D89E0 (0x000D89E0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000D89E0
{
public:
    int sub_000D89E0();
    char m_pad00[0x228];
    int m_Field228; // +0x228
};

int Class_000D89E0::sub_000D89E0()
{
    return m_Field228 != 0;
}
