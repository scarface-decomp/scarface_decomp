// bin: xb
// va: 0x00186790
// tool: the portal's starter code (no AI)
// sub_00186790 (0x00186790, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_000C3030();
};

extern "C" float DAT_0039D65C;
extern "C" char DAT_003B7F14[];
extern "C" void __cdecl sub_00022950(void);

class Class_00186790
{
public:
    Class_00186790* sub_00186790();
    int m_Field00; // +0x00
    char m_pad04[0x8];
    float m_Field0C; // +0x0C
    char m_pad10[0x4];
    Field14 m_Field14; // +0x14
};

Class_00186790* Class_00186790::sub_00186790()
{
    sub_00022950();
    m_Field00 = (int)DAT_003B7F14;
    m_Field14.sub_000C3030();
    m_Field0C = DAT_0039D65C;
    return this;
}
