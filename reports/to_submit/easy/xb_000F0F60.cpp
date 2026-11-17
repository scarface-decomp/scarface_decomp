// bin: xb
// va: 0x000F0F60
// tool: the portal's starter code (no AI)
// sub_000F0F60 (0x000F0F60, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000F0F60
{
public:
    void sub_000F0F60(float a1, float a2, float a3, float a4);
    char m_pad00[0x340];
    float m_Field340; // +0x340
    float m_Field344; // +0x344
    float m_Field348; // +0x348
    float m_Field34C; // +0x34C
};

void Class_000F0F60::sub_000F0F60(float a1, float a2, float a3, float a4)
{
    m_Field340 = a1;
    m_Field344 = a2;
    m_Field348 = a3;
    m_Field34C = a4;
}
