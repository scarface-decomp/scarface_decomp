// bin: proto
// va: 0x001D2270
// tool: the portal's starter code (no AI)
// sub_001D2270 (0x001D2270, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field38
{
    void sub_0009AF10();
};

extern "C" float DAT_0037D068;
extern "C" char DAT_003A79C4[];

class Class_001D2270
{
public:
    Class_001D2270* sub_001D2270(int a1, int a2);
    void sub_001D1840(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x28];
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
    float m_Field34; // +0x34
    Field38 m_Field38; // +0x38
};

Class_001D2270* Class_001D2270::sub_001D2270(int a1, int a2)
{
    float t2;

    sub_001D1840(a1, a2);
    t2 = DAT_0037D068;
    m_Field00 = (int)DAT_003A79C4;
    m_Field2C = 0;
    m_Field30 = 0;
    m_Field34 = t2;
    m_Field38.sub_0009AF10();
    return this;
}
