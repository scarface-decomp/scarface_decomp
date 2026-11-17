// bin: xb
// va: 0x001217C0
// tool: the portal's starter code (no AI)
// sub_001217C0 (0x001217C0, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AEDB0[];
extern "C" void __cdecl sub_0011E180(void);

class Class_001217C0
{
public:
    Class_001217C0* sub_001217C0(int a1, int a2, float a3);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    float m_Field20; // +0x20
};

Class_001217C0* Class_001217C0::sub_001217C0(int a1, int a2, float a3)
{
    sub_0011E180();
    m_Field08 = a1;
    m_Field00 = (int)DAT_003AEDB0;
    m_Field0C = *(int*)a2;
    m_Field10 = *(int*)(a2 + 4);
    m_Field14 = *(int*)(a2 + 8);
    m_Field18 = *(int*)(a2 + 12);
    m_Field1C = *(int*)(a2 + 16);
    m_Field20 = a3;
    return this;
}
