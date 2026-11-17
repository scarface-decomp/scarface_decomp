// bin: xb
// va: 0x00141060
// tool: the portal's starter code (no AI)
// sub_00141060 (0x00141060, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0013DF50(void);

class Class_00141060
{
public:
    void sub_00141060(float a1);
    char m_pad00[0x15C];
    int m_Field15C; // +0x15C
    int m_Field160; // +0x160
};

void Class_00141060::sub_00141060(float a1)
{
    int t1;

    t1 = m_Field15C;
    if ((unsigned int)m_Field15C < (unsigned int)m_Field160) {
        m_Field15C = t1 + 4;
        if (!t1) goto L_25;
        *(float*)t1 = a1;
    }
L_25:
    sub_0013DF50();
}
