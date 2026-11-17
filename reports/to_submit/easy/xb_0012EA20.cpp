// bin: xb
// va: 0x0012EA20
// tool: the portal's starter code (no AI)
// sub_0012EA20 (0x0012EA20, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B14CC[];

class Class_0012EA20
{
public:
    Class_0012EA20* sub_0012EA20(int a1, float a2, float a3, bool a4);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    bool m_Field1C; // +0x1C
    bool m_Field1D; // +0x1D
    bool m_Field1E; // +0x1E
};

Class_0012EA20* Class_0012EA20::sub_0012EA20(int a1, float a2, float a3, bool a4)
{
    m_Field04 = 9;
    m_Field00 = (int)DAT_003B14CC;
    m_Field08 = *(int*)a1;
    m_Field0C = *(int*)(a1 + 4);
    m_Field10 = *(int*)(a1 + 8);
    m_Field14 = a2;
    m_Field1C = false;
    m_Field18 = a3;
    m_Field1D = a4;
    m_Field1E = false;
    return this;
}
