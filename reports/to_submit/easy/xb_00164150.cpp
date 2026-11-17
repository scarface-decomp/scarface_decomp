// bin: xb
// va: 0x00164150
// tool: the portal's starter code (no AI)
// sub_00164150 (0x00164150, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00164150
{
public:
    int sub_00164150();
    char m_pad00[0x2A4];
    int m_Field2A4; // +0x2A4
};

int Class_00164150::sub_00164150()
{
    return m_Field2A4 != 0;
}
