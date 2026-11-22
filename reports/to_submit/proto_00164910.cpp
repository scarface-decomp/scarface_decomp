// bin: proto
// va: 0x00164910
// what: 
// tool: the portal's starter code (no AI)

// sub_00164910 (Proto 0x00164910, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_000AABF0();
};

extern "C" float DAT_0037CE60;
extern "C" char DAT_003958D4[];
extern "C" void __cdecl sub_000205E0(void);

class Class_00164910
{
public:
    Class_00164910* sub_00164910();
    int m_Field00; // +0x00
    char m_pad04[0x8];
    float m_Field0C; // +0x0C
    char m_pad10[0x4];
    Field14 m_Field14; // +0x14
};

Class_00164910* Class_00164910::sub_00164910()
{
    sub_000205E0();
    m_Field00 = (int)DAT_003958D4;
    m_Field14.sub_000AABF0();
    m_Field0C = DAT_0037CE60;
    return this;
}
