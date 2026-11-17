// bin: xb
// va: 0x00146140
// tool: the portal's starter code (no AI)
// sub_00146140 (0x00146140, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field28
{
    void sub_00098B70(int);
};

extern "C" float DAT_003A3E48;
extern "C" char DAT_003B23CC[];

class Class_00146140
{
public:
    Class_00146140* sub_00146140(int a1, int a2);
    void sub_0014A5B0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x24];
    Field28 m_Field28; // +0x28
    char m_pad29[0x3];
    int m_Field2C; // +0x2C
    float m_Field30; // +0x30
};

Class_00146140* Class_00146140::sub_00146140(int a1, int a2)
{
    float t3;

    sub_0014A5B0(a1, a2);
    m_Field00 = (int)DAT_003B23CC;
    m_Field28.sub_00098B70(0);
    t3 = DAT_003A3E48;
    m_Field2C = 0;
    m_Field30 = t3;
    return this;
}
