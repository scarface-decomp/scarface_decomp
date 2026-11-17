// bin: xb
// va: 0x00162440
// tool: the portal's starter code (no AI)
// sub_00162440 (0x00162440, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00162440
{
public:
    void sub_00162440(float a1, float a2, float a3);
    char m_pad00[0x44];
    float m_Field44; // +0x44
    float m_Field48; // +0x48
    float m_Field4C; // +0x4C
};

void Class_00162440::sub_00162440(float a1, float a2, float a3)
{
    m_Field44 = a1;
    m_Field48 = a2;
    m_Field4C = a3;
}
