// bin: xb
// va: 0x00012550
// tool: the portal's starter code (no AI)
// sub_00012550 (0x00012550, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00012550
{
public:
    int sub_00012550(int a1);
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

int Class_00012550::sub_00012550(int a1)
{
    m_Field00 = *(float*)a1 + m_Field00;
    m_Field04 = *(float*)(a1 + 4) + m_Field04;
    m_Field08 = *(float*)(a1 + 8) + m_Field08;
    return a1;
}
