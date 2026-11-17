// bin: proto
// va: 0x00098AF0
// tool: the portal's starter code (no AI)
// sub_00098AF0 (0x00098AF0, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_00383E54;
extern "C" float DAT_003850E8;
extern "C" float DAT_003895FC;
extern "C" float DAT_003AB1D0;

class Class_00098AF0
{
public:
    Class_00098AF0* sub_00098AF0();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_00098AF0* Class_00098AF0::sub_00098AF0()
{
    float t1, t2, t4;

    t1 = DAT_003895FC;
    t2 = DAT_003AB1D0;
    m_Field00 = t1;
    m_Field08 = t1;
    m_Field0C = DAT_003850E8;
    t4 = DAT_00383E54;
    m_Field04 = t2;
    m_Field10 = t4;
    return this;
}
