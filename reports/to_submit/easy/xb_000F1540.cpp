// bin: xb
// va: 0x000F1540
// tool: the portal's starter code (no AI)
// sub_000F1540 (0x000F1540, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000F1540
{
public:
    void sub_000F1540(float a1, float a2, float a3, float a4, float a5);
    char m_pad00[0x304];
    float m_Field304; // +0x304
    float m_Field308; // +0x308
    float m_Field30C; // +0x30C
    float m_Field310; // +0x310
    float m_Field314; // +0x314
    bool m_Field318; // +0x318
};

void Class_000F1540::sub_000F1540(float a1, float a2, float a3, float a4, float a5)
{
    m_Field304 = a1;
    m_Field308 = a2;
    m_Field30C = a3;
    m_Field310 = a4;
    m_Field314 = a5;
    m_Field318 = true;
}
