// bin: proto
// va: 0x001C39F0
// tool: the portal's starter code (no AI)
// sub_001C39F0 (0x001C39F0, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;
extern "C" float DAT_0038ADF0;
extern "C" char DAT_003A5154[];
extern "C" float DAT_003AA7B8;

class Class_001C39F0
{
public:
    Class_001C39F0* sub_001C39F0(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    float m_Field24; // +0x24
    float m_Field28; // +0x28
    float m_Field2C; // +0x2C
    float m_Field30; // +0x30
};

Class_001C39F0* Class_001C39F0::sub_001C39F0(int a1, int a2)
{
    float t2, t3, t4;

    sub_00028470(a1, a2);
    t2 = DAT_0037CE50;
    t3 = DAT_0038ADF0;
    m_Field24 = t2;
    m_Field2C = t2;
    t4 = DAT_003AA7B8;
    m_Field20 = 65535;
    m_Field22 = false;
    m_Field00 = (int)DAT_003A5154;
    m_Field28 = t3;
    m_Field30 = t4;
    return this;
}
