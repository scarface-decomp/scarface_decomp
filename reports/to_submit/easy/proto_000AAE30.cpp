// bin: proto
// va: 0x000AAE30
// tool: the portal's starter code (no AI)
// sub_000AAE30 (0x000AAE30, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000AAE30
{
public:
    int sub_000AAE30();
    char m_pad00[0x4];
    int m_Field04; // +0x04
};

int Class_000AAE30::sub_000AAE30()
{
    return m_Field04 != 0;
}
