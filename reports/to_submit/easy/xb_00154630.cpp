// bin: xb
// va: 0x00154630
// tool: the portal's starter code (no AI)
// sub_00154630 (0x00154630, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00154630
{
public:
    bool sub_00154630(bool a1, float a2, float a3, float a4, float a5);
    char m_pad00[0x2A5];
    bool m_Field2A5; // +0x2A5
    char m_pad2A6[0x2];
    float m_Field2A8; // +0x2A8
    float m_Field2AC; // +0x2AC
    float m_Field2B0; // +0x2B0
    float m_Field2B4; // +0x2B4
};

bool Class_00154630::sub_00154630(bool a1, float a2, float a3, float a4, float a5)
{
    m_Field2A8 = a2;
    m_Field2AC = a3;
    m_Field2B0 = a4;
    m_Field2A5 = a1;
    m_Field2B4 = a5;
    return a1;
}
