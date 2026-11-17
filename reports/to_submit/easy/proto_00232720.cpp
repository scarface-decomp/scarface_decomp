// bin: proto
// va: 0x00232720
// tool: the portal's starter code (no AI)
// sub_00232720 (0x00232720, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00232720
{
public:
    bool sub_00232720();
    char m_pad00[0x38];
    unsigned char : 2;
    unsigned char m_Field38_bit2 : 1; // +0x38, bit 2
};

bool Class_00232720::sub_00232720()
{
    return m_Field38_bit2;
}
