// bin: xb
// va: 0x00134F20
// tool: the portal's starter code (no AI)
// sub_00134F20 (0x00134F20, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B1BF8[];

class Class_00134F20
{
public:
    Class_00134F20* sub_00134F20(float a1, int a2);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    float m_Field14; // +0x14
    bool m_Field18; // +0x18
    bool m_Field19; // +0x19
};

Class_00134F20* Class_00134F20::sub_00134F20(float a1, int a2)
{
    m_Field04 = 9;
    m_Field00 = (int)DAT_003B1BF8;
    m_Field14 = a1;
    m_Field18 = false;
    m_Field19 = !a2;
    if (a2) {
        m_Field08 = *(int*)a2;
        m_Field0C = *(int*)(a2 + 4);
        m_Field10 = *(int*)(a2 + 8);
    }
    return this;
}
