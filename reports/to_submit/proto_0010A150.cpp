// bin: proto
// va: 0x0010A150
// what: 
// tool: the portal's starter code (no AI)

// sub_0010A150 (Proto 0x0010A150, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0010A150
{
public:
    int sub_0010A150(int a1, float a2, float a3);
    char m_pad00[0x54];
    int m_Field54; // +0x54
    float m_Field58; // +0x58
    float m_Field5C; // +0x5C
};

int Class_0010A150::sub_0010A150(int a1, float a2, float a3)
{
    m_Field5C = a2;
    m_Field54 = a1;
    m_Field58 = a3;
    return a1;
}
