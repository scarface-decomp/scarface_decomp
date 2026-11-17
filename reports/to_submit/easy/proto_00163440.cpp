// bin: proto
// va: 0x00163440
// tool: the portal's starter code (no AI)
// sub_00163440 (0x00163440, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE60;
extern "C" float DAT_00390DF4;
extern "C" char DAT_00394C14[];
extern "C" void __cdecl sub_000205E0(void);

class Class_00163440
{
public:
    Class_00163440* sub_00163440();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    int m_Field28; // +0x28
};

Class_00163440* Class_00163440::sub_00163440()
{
    float t2, t3;

    sub_000205E0();
    t2 = DAT_00390DF4;
    t3 = DAT_0037CE60;
    m_Field20 = 0;
    m_Field24 = 0;
    m_Field28 = 0;
    m_Field00 = (int)DAT_00394C14;
    m_Field14 = t2;
    m_Field18 = t3;
    m_Field1C = t2;
    return this;
}
