// bin: xb
// va: 0x00164340
// tool: the portal's starter code (no AI)
// sub_00164340 (0x00164340, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00164340
{
public:
    int sub_00164340();
    char m_pad00[0x2E8];
    int m_Field2E8; // +0x2E8
};

int Class_00164340::sub_00164340()
{
    return m_Field2E8 != 0;
}
