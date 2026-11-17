// bin: xb
// va: 0x001392F0
// tool: the portal's starter code (no AI)
// sub_001392F0 (0x001392F0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001392F0
{
public:
    int sub_001392F0(int a1);
    char m_pad00[0x44];
    int m_Field44; // +0x44
    float m_Field48; // +0x48
    char m_pad4C[0x4];
    int m_Field50; // +0x50
    float m_Field54; // +0x54
};

int Class_001392F0::sub_001392F0(int a1)
{
    int r_eax;

    r_eax = a1;
    if (a1 != m_Field44) {
        m_Field44 = a1;
        r_eax = m_Field50;
        m_Field48 = 0.0f;
        if (!r_eax) goto L_27;
        m_Field50 = 0;
        m_Field54 = 0.0f;
    }
L_27:
    return r_eax;
}
