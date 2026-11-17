// bin: xb
// va: 0x000A6E90
// tool: the portal's starter code (no AI)
// sub_000A6E90 (0x000A6E90, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field34
{
    void sub_00087850();
};

extern "C" float DAT_0039D65C;
extern "C" void __cdecl sub_000873C0(void);

class Class_000A6E90
{
public:
    Class_000A6E90* sub_000A6E90();
    char m_pad00[0x2C];
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
    Field34 m_Field34; // +0x34
    char m_pad35[0x47];
    float m_Field7C; // +0x7C
};

Class_000A6E90* Class_000A6E90::sub_000A6E90()
{
    sub_000873C0();
    m_Field2C = -1;
    m_Field30 = 0;
    m_Field34.sub_00087850();
    m_Field7C = DAT_0039D65C;
    return this;
}
