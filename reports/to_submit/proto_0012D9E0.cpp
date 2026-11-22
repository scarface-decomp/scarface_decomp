// bin: proto
// va: 0x0012D9E0
// what: 
// tool: the portal's starter code (no AI)

// sub_0012D9E0 (Proto 0x0012D9E0, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_00390010;
extern "C" char DAT_003909EC[];

class Class_0012D9E0
{
public:
    Class_0012D9E0* sub_0012D9E0(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    float m_Field28; // +0x28
    int m_Field2C; // +0x2C
};

Class_0012D9E0* Class_0012D9E0::sub_0012D9E0(int a1, int a2)
{
    float t2;

    sub_00028470(a1, a2);
    t2 = DAT_00390010;
    m_Field20 = 0;
    m_Field24 = 0;
    m_Field00 = (int)DAT_003909EC;
    m_Field28 = t2;
    m_Field2C = 3;
    return this;
}
