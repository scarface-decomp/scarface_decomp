// bin: proto
// va: 0x001193C0
// what: 
// tool: the portal's starter code (no AI)

// sub_001193C0 (Proto 0x001193C0, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038F914[];
extern "C" int __cdecl sub_0006C370(int, int);

class Class_001193C0
{
public:
    Class_001193C0* sub_001193C0(int a1, float a2, bool a3);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    float m_Field0C; // +0x0C
    bool m_Field10; // +0x10
    bool m_Field11; // +0x11
};

Class_001193C0* Class_001193C0::sub_001193C0(int a1, float a2, bool a3)
{
    m_Field04 = 21;
    m_Field00 = (int)DAT_0038F914;
    m_Field0C = a2;
    m_Field10 = false;
    m_Field11 = a3;
    m_Field08 = sub_0006C370(a1, 0);
    return this;
}
