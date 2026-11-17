// bin: xb
// va: 0x00280640
// tool: the portal's starter code (no AI)
// sub_00280640 (0x00280640, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00280640
{
public:
    bool sub_00280640();
    char m_pad00[0x38];
    unsigned char : 2;
    unsigned char m_Field38_bit2 : 1; // +0x38, bit 2
};

bool Class_00280640::sub_00280640()
{
    return m_Field38_bit2;
}
