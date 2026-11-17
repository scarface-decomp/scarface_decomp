// bin: xb
// va: 0x00026720
// tool: the portal's starter code (no AI)
// sub_00026720 (0x00026720, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00026720
{
public:
    int sub_00026720(float a1);
    char m_pad00[0x30];
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    int m_Field38; // +0x38
};

int Class_00026720::sub_00026720(float a1)
{
    int r_eax;

    r_eax = m_Field30;
    if (r_eax < m_Field34) {
        *(float*)(m_Field38 + (r_eax * 4)) = a1;
        m_Field30 += 1;
    }
    return r_eax;
}
