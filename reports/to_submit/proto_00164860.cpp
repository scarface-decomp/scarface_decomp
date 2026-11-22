// bin: proto
// va: 0x00164860
// what: 
// tool: the portal's starter code (no AI)

// sub_00164860 (Proto 0x00164860, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_003957C4[];
extern "C" void __cdecl sub_000205E0(void);

class Class_00164860
{
public:
    Class_00164860* sub_00164860();
    int m_Field00; // +0x00
    char m_pad04[0x8];
    float m_Field0C; // +0x0C
    char m_pad10[0x4];
    Field14 m_Field14; // +0x14
    char m_pad15[0x3];
    Field14 m_Field18; // +0x18
};

Class_00164860* Class_00164860::sub_00164860()
{
    sub_000205E0();
    m_Field00 = (int)DAT_003957C4;
    m_Field14.sub_00200310((int)DAT_0037CD30);
    m_Field18.sub_00200310((int)DAT_0037CD30);
    m_Field0C = 0.0f;
    return this;
}
