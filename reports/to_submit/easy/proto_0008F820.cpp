// bin: proto
// va: 0x0008F820
// tool: the portal's starter code (no AI)
// sub_0008F820 (0x0008F820, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037E6C0;
extern "C" float DAT_00383E58;
extern "C" float DAT_00383E5C;
extern "C" float DAT_00383E60;

class Class_0008F820
{
public:
    Class_0008F820* sub_0008F820();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
};

Class_0008F820* Class_0008F820::sub_0008F820()
{
    float t2, t4;

    m_Field00 = DAT_00383E60;
    t2 = DAT_0037E6C0;
    m_Field08 = t2;
    m_Field10 = t2;
    m_Field18 = t2;
    m_Field04 = DAT_00383E5C;
    t4 = DAT_00383E58;
    m_Field0C = t4;
    m_Field14 = t4;
    m_Field1C = t4;
    return this;
}
