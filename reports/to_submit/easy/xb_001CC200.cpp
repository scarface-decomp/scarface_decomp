// bin: xb
// va: 0x001CC200
// tool: the portal's starter code (no AI)
// sub_001CC200 (0x001CC200, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C49A8[];
extern "C" char DAT_003C49C4[];

class Class_001CC200
{
public:
    Class_001CC200* sub_001CC200(int a1, int a2);
    void sub_001CA680(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x60];
    int m_Field64; // +0x64
    char m_pad68[0x14];
    bool m_Field7C; // +0x7C
    char m_pad7D[0x3];
    float m_Field80; // +0x80
};

Class_001CC200* Class_001CC200::sub_001CC200(int a1, int a2)
{
    sub_001CA680(a1, a2);
    m_Field00 = (int)DAT_003C49C4;
    m_Field64 = (int)DAT_003C49A8;
    m_Field7C = false;
    m_Field80 = 0.0f;
    return this;
}
