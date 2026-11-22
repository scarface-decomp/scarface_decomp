// bin: proto
// va: 0x00164570
// what: 
// tool: the portal's starter code (no AI)

// sub_00164570 (Proto 0x00164570, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_00395274[];
extern "C" void __cdecl sub_000205E0(void);

class Class_00164570
{
public:
    Class_00164570* sub_00164570();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
    char m_pad15[0x3];
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
};

Class_00164570* Class_00164570::sub_00164570()
{
    sub_000205E0();
    m_Field00 = (int)DAT_00395274;
    m_Field14.sub_00200310((int)DAT_0037CD30);
    m_Field24 = 0.0f;
    m_Field20 = 0.0f;
    m_Field1C = 0.0f;
    m_Field18 = 0.0f;
    return this;
}
