// bin: xb
// va: 0x00058390
// tool: the portal's starter code (no AI)
// sub_00058390 (0x00058390, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;

class Class_00058390
{
public:
    void sub_00058390(float a1);
    char m_pad00[0x68];
    float m_Field68; // +0x68
    float m_Field6C; // +0x6C
    char m_pad70[0x4];
    float m_Field74; // +0x74
    char m_pad78[0x8];
    unsigned char m_Field80; // +0x80
};

void Class_00058390::sub_00058390(float a1)
{
    unsigned char t1;

    t1 = m_Field80;
    m_Field6C = 0.0f;
    m_Field74 = DAT_0039D664;
    m_Field68 = a1;
    m_Field80 = (unsigned char)(t1 | 4);
}
