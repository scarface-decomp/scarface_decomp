// bin: xb
// va: 0x00134A20
// tool: the portal's starter code (no AI)
// sub_00134A20 (0x00134A20, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;
extern "C" char DAT_003B1A48[];

class Class_00134A20
{
public:
    Class_00134A20* sub_00134A20(int a1, float a2, bool a3);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    float m_Field0C; // +0x0C
    char m_pad10[0x4];
    float m_Field14; // +0x14
    bool m_Field18; // +0x18
};

Class_00134A20* Class_00134A20::sub_00134A20(int a1, float a2, bool a3)
{
    m_Field0C = DAT_0039D65C;
    m_Field04 = 25;
    m_Field00 = (int)DAT_003B1A48;
    m_Field08 = a1;
    m_Field14 = a2;
    m_Field18 = a3;
    if (a1 > 0) {
        if (a1 < 21) goto L_45;
    }
    m_Field08 = 17;
L_45:
    return this;
}
