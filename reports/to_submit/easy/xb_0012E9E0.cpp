// bin: xb
// va: 0x0012E9E0
// tool: the portal's starter code (no AI)
// sub_0012E9E0 (0x0012E9E0, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B14CC[];

class Class_0012E9E0
{
public:
    Class_0012E9E0* sub_0012E9E0(int a1, float a2, float a3, bool a4);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x8];
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    bool m_Field1C; // +0x1C
    bool m_Field1D; // +0x1D
    bool m_Field1E; // +0x1E
};

Class_0012E9E0* Class_0012E9E0::sub_0012E9E0(int a1, float a2, float a3, bool a4)
{
    m_Field14 = a2;
    m_Field04 = 9;
    m_Field00 = (int)DAT_003B14CC;
    m_Field08 = a1;
    m_Field1C = true;
    m_Field18 = a3;
    m_Field1D = a4;
    m_Field1E = false;
    return this;
}
