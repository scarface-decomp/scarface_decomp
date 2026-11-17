// bin: xb
// va: 0x00121630
// tool: the portal's starter code (no AI)
// sub_00121630 (0x00121630, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AEC90[];
extern "C" void __cdecl sub_0011E180(void);

class Class_00121630
{
public:
    Class_00121630* sub_00121630(int a1, float a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

Class_00121630* Class_00121630::sub_00121630(int a1, float a2)
{
    sub_0011E180();
    m_Field08 = a1;
    m_Field00 = (int)DAT_003AEC90;
    m_Field0C = a2;
    return this;
}
