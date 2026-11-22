// bin: proto
// va: 0x00040F80
// what: 
// tool: the portal's starter code (no AI)

// sub_00040F80 (Proto 0x00040F80, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;
extern "C" float DAT_0037F750;

class Class_00040F80
{
public:
    Class_00040F80* sub_00040F80();
    bool m_Field00; // +0x00
    char m_pad01[0x3];
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
};

Class_00040F80* Class_00040F80::sub_00040F80()
{
    m_Field14 = DAT_0037CE50;
    m_Field18 = DAT_0037F750;
    m_Field04 = 128;
    m_Field08 = 128;
    m_Field0C = 128;
    m_Field10 = 128;
    m_Field00 = false;
    m_Field1C = 0.0f;
    return this;
}
