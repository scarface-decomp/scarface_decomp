// bin: proto
// va: 0x00018470
// tool: the portal's starter code (no AI)
// sub_00018470 (0x00018470, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00018470
{
public:
    float sub_00018470();
    int m_Field00; // +0x00
};

float Class_00018470::sub_00018470()
{
    return *(float*)(m_Field00 + 64);
}
