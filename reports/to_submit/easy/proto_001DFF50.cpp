// bin: proto
// va: 0x001DFF50
// tool: the portal's starter code (no AI)
// sub_001DFF50 (0x001DFF50, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldF8
{
    void sub_0008D4A0(int);
};

extern "C" char DAT_003A9E44[];

class Class_001DFF50
{
public:
    Class_001DFF50* sub_001DFF50(int a1, int a2);
    void sub_001D8710(int, int);
    int m_Field00; // +0x00
    char m_pad04[0xF4];
    FieldF8 m_FieldF8; // +0xF8
    char m_padF9[0x3];
    int m_FieldFC; // +0xFC
    bool m_Field100; // +0x100
    bool m_Field101; // +0x101
    char m_pad102[0x2];
    float m_Field104; // +0x104
    bool m_Field108; // +0x108
};

Class_001DFF50* Class_001DFF50::sub_001DFF50(int a1, int a2)
{
    sub_001D8710(a1, a2);
    m_Field00 = (int)DAT_003A9E44;
    m_FieldF8.sub_0008D4A0(0);
    m_FieldFC = 0;
    m_Field100 = false;
    m_Field101 = false;
    m_Field108 = false;
    m_Field104 = 0.0f;
    return this;
}
