// bin: proto
// va: 0x00099B00
// tool: the portal's starter code (no AI)
// sub_00099B00 (0x00099B00, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE60;
extern "C" char DAT_0038404C[];

class Class_00099B00
{
public:
    Class_00099B00* sub_00099B00();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    bool m_Field08; // +0x08
    char m_pad09[0x3];
    bool m_Field0C; // +0x0C
    char m_pad0D[0x3];
    int m_Field10; // +0x10
    bool m_Field14; // +0x14
    bool m_Field15; // +0x15
    char m_pad16[0x2];
    float m_Field18; // +0x18
    bool m_Field1C; // +0x1C
    bool m_Field1D; // +0x1D
};

Class_00099B00* Class_00099B00::sub_00099B00()
{
    float t1;

    t1 = DAT_0037CE60;
    m_Field04 = 0;
    m_Field08 = false;
    m_Field0C = false;
    m_Field00 = (int)DAT_0038404C;
    m_Field10 = 0;
    m_Field14 = false;
    m_Field15 = false;
    m_Field18 = t1;
    m_Field1C = false;
    m_Field1D = false;
    return this;
}
