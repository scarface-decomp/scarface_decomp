// bin: proto
// va: 0x001E18C0
// tool: the portal's starter code (no AI)
// sub_001E18C0 (0x001E18C0, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00461F90;

class Class_001E18C0
{
public:
    Class_001E18C0* sub_001E18C0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    bool m_Field18; // +0x18
    bool m_Field19; // +0x19
    char m_pad1A[0x1A];
    int m_Field34; // +0x34
    int m_Field38; // +0x38
};

Class_001E18C0* Class_001E18C0::sub_001E18C0()
{
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field08 = DAT_00461F90;
    m_Field0C = 0.0f;
    m_Field10 = 0.0f;
    m_Field14 = 0.0f;
    m_Field18 = false;
    m_Field19 = true;
    m_Field34 = DAT_00461F90;
    m_Field38 = DAT_00461F90;
    return this;
}
