// bin: proto
// va: 0x00041060
// what: 
// tool: the portal's starter code (no AI)

// sub_00041060 (Proto 0x00041060, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;

class Class_00041060
{
public:
    Class_00041060* sub_00041060();
    bool m_Field00; // +0x00
    char m_pad01[0x3];
    float m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    float m_Field14; // +0x14
};

Class_00041060* Class_00041060::sub_00041060()
{
    float t1;

    t1 = DAT_0037CE50;
    m_Field00 = false;
    m_Field04 = t1;
    m_Field14 = t1;
    m_Field08 = 128;
    m_Field0C = 128;
    m_Field10 = 128;
    return this;
}
