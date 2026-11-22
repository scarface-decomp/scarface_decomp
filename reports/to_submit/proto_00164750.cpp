// bin: proto
// va: 0x00164750
// what: 
// tool: the portal's starter code (no AI)

// sub_00164750 (Proto 0x00164750, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_003956B4[];
extern "C" void __cdecl sub_000205E0(void);

class Class_00164750
{
public:
    Class_00164750* sub_00164750();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
    char m_pad15[0xF];
    float m_Field24; // +0x24
};

Class_00164750* Class_00164750::sub_00164750()
{
    sub_000205E0();
    m_Field00 = (int)DAT_003956B4;
    m_Field14.sub_00200310((int)DAT_0037CD30);
    m_Field24 = 0.0f;
    return this;
}
