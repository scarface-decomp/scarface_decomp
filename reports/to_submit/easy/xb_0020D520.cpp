// bin: xb
// va: 0x0020D520
// tool: the portal's starter code (no AI)
// sub_0020D520 (0x0020D520, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    void sub_000A6DC0();
};

extern "C" float DAT_0039D91C;
extern "C" char DAT_003CDB9C[];

class Class_0020D520
{
public:
    Class_0020D520* sub_0020D520(int a1, int a2);
    void sub_0020CB30(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x20];
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    float m_Field2C; // +0x2C
    Field30 m_Field30; // +0x30
};

Class_0020D520* Class_0020D520::sub_0020D520(int a1, int a2)
{
    float t2;

    sub_0020CB30(a1, a2);
    t2 = DAT_0039D91C;
    m_Field00 = (int)DAT_003CDB9C;
    m_Field24 = 0;
    m_Field28 = 0;
    m_Field2C = t2;
    m_Field30.sub_000A6DC0();
    return this;
}
