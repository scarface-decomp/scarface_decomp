// bin: proto
// va: 0x00092AA0
// tool: the portal's starter code (no AI)
// sub_00092AA0 (0x00092AA0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037F534;

class Class_00092AA0
{
public:
    void sub_00092AA0();
    char m_pad00[0x18];
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    float m_Field28; // +0x28
    float m_Field2C; // +0x2C
    float m_Field30; // +0x30
    float m_Field34; // +0x34
};

void Class_00092AA0::sub_00092AA0()
{
    float t1;

    t1 = DAT_0037F534;
    m_Field18 = m_Field1C * t1;
    m_Field20 = m_Field24 * t1;
    m_Field2C = m_Field28 * t1;
    m_Field34 = m_Field30 * t1;
}
