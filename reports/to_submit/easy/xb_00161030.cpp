// bin: xb
// va: 0x00161030
// tool: the portal's starter code (no AI)
// sub_00161030 (0x00161030, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00161030
{
public:
    int sub_00161030();
    char m_pad00[0x30];
    int m_Field30; // +0x30
};

int Class_00161030::sub_00161030()
{
    return m_Field30 != 0;
}
