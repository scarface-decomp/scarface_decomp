// bin: proto
// va: 0x0008F760
// tool: the portal's starter code (no AI)
// sub_0008F760 (0x0008F760, 90 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037D4D0;
extern "C" float DAT_0037F688;
extern "C" float DAT_00383E54;
extern "C" float DAT_003850E8;
extern "C" float DAT_003915CC;

class Class_0008F760
{
public:
    Class_0008F760* sub_0008F760();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
};

Class_0008F760* Class_0008F760::sub_0008F760()
{
    m_Field04 = DAT_003850E8;
    m_Field08 = DAT_0037F688;
    m_Field0C = DAT_003915CC;
    m_Field10 = DAT_0037D4D0;
    m_Field14 = 0.0f;
    m_Field18 = 0.0f;
    m_Field1C = 0.0f;
    m_Field20 = 0.0f;
    m_Field00 = DAT_00383E54;
    return this;
}
