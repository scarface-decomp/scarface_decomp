// bin: xb
// va: 0x001176D0
// tool: the portal's starter code (no AI)
// sub_001176D0 (0x001176D0, 89 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001176D0
{
public:
    void sub_001176D0(int a1, int a2);
    void sub_001175E0(int);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    char m_pad08[0x28];
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    int m_Field38; // +0x38
    char m_pad3C[0x44];
    bool m_Field80; // +0x80
    bool m_Field81; // +0x81
};

void Class_001176D0::sub_001176D0(int a1, int a2)
{
    *(float*)(a2 + 8) = 0.0f;
    *(float*)(a2 + 4) = 0.0f;
    *(float*)a2 = 0.0f;
    if (m_Field00 != m_Field04) {
        sub_001175E0(3);
        m_Field81 = true;
    }
    if (!m_Field80) {
        m_Field30 = *(int*)a1;
        m_Field34 = *(int*)(a1 + 4);
        m_Field38 = *(int*)(a1 + 8);
        m_Field80 = true;
    }
}
