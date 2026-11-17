// bin: proto
// va: 0x00018480
// tool: the portal's starter code (no AI)
// sub_00018480 (0x00018480, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00018480
{
public:
    int sub_00018480(float a1);
    int m_Field00; // +0x00
};

int Class_00018480::sub_00018480(float a1)
{
    int t1;

    t1 = m_Field00;
    *(float*)(m_Field00 + 64) = a1;
    return t1;
}
