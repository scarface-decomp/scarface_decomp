// bin: proto
// va: 0x00136010
// tool: the portal's starter code (no AI)
// sub_00136010 (0x00136010, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00136010
{
public:
    float sub_00136010();
    char m_pad00[0x84];
    int m_Field84; // +0x84
};

float Class_00136010::sub_00136010()
{
    return *(float*)(m_Field84 + 16);
}
