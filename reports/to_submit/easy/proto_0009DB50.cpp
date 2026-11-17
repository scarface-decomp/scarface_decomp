// bin: proto
// va: 0x0009DB50
// tool: the portal's starter code (no AI)
// sub_0009DB50 (0x0009DB50, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_00382B18;
extern "C" float DAT_00383F68;
extern "C" float DAT_003841CC;
extern "C" float DAT_003850D4;

class Class_0009DB50
{
public:
    Class_0009DB50* sub_0009DB50();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

Class_0009DB50* Class_0009DB50::sub_0009DB50()
{
    m_Field04 = DAT_003850D4;
    m_Field0C = DAT_00382B18;
    m_Field00 = DAT_00383F68;
    m_Field08 = DAT_003841CC;
    return this;
}
