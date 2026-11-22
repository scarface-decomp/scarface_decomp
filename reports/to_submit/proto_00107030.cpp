// bin: proto
// va: 0x00107030
// what: 
// tool: the portal's starter code (no AI)

// sub_00107030 (Proto 0x00107030, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;
extern "C" char DAT_0038CDCC[];

class Class_00107030
{
public:
    Class_00107030* sub_00107030(int a1, int a2);
    void sub_0010DC20(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x50];
    int m_Field54; // +0x54
    float m_Field58; // +0x58
    float m_Field5C; // +0x5C
};

Class_00107030* Class_00107030::sub_00107030(int a1, int a2)
{
    float t2;

    sub_0010DC20(a1, a2);
    m_Field58 = 0.0f;
    t2 = DAT_0037CE50;
    m_Field00 = (int)DAT_0038CDCC;
    m_Field54 = 0;
    m_Field5C = t2;
    return this;
}
