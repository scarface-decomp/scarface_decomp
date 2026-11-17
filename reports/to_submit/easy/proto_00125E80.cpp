// bin: proto
// va: 0x00125E80
// tool: the portal's starter code (no AI)
// sub_00125E80 (0x00125E80, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001233F0(void);

class Class_00125E80
{
public:
    void sub_00125E80(float a1);
    char m_pad00[0x158];
    int m_Field158; // +0x158
    int m_Field15C; // +0x15C
};

void Class_00125E80::sub_00125E80(float a1)
{
    int t1;

    t1 = m_Field158;
    if ((unsigned int)m_Field158 < (unsigned int)m_Field15C) {
        m_Field158 = t1 + 4;
        if (!t1) goto L_25;
        *(float*)t1 = a1;
    }
L_25:
    sub_001233F0();
}
