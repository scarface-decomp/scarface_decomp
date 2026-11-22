// bin: proto
// va: 0x00121B30
// what: 
// tool: the portal's starter code (no AI)

// sub_00121B30 (Proto 0x00121B30, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039014C;
extern "C" char DAT_003901E4[];

class Class_00121B30
{
public:
    Class_00121B30* sub_00121B30(int a1, int a2);
    void sub_001210D0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    float m_Field38; // +0x38
    float m_Field3C; // +0x3C
};

Class_00121B30* Class_00121B30::sub_00121B30(int a1, int a2)
{
    float t2;

    sub_001210D0(a1, a2);
    t2 = DAT_0039014C;
    m_Field00 = (int)DAT_003901E4;
    m_Field34 = 4;
    m_Field38 = t2;
    m_Field3C = t2;
    m_Field30 = 0;
    return this;
}
