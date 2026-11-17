// bin: proto
// va: 0x00147DF0
// tool: the portal's starter code (no AI)
// sub_00147DF0 (0x00147DF0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00147DF0
{
public:
    int sub_00147DF0();
    char m_pad00[0x280];
    int m_Field280; // +0x280
};

int Class_00147DF0::sub_00147DF0()
{
    return m_Field280 != 0;
}
