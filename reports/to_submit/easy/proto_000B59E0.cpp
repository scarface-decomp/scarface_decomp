// bin: proto
// va: 0x000B59E0
// tool: the portal's starter code (no AI)
// sub_000B59E0 (0x000B59E0, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037E6C0;
extern "C" float DAT_003841D0;
extern "C" float DAT_003841EC;
extern "C" float DAT_003850E8;
extern "C" float DAT_003AA7B8;

class Class_000B59E0
{
public:
    Class_000B59E0* sub_000B59E0();
    int m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
};

Class_000B59E0* Class_000B59E0::sub_000B59E0()
{
    float t5;

    m_Field04 = DAT_003AA7B8;
    m_Field0C = DAT_0037E6C0;
    m_Field14 = DAT_003850E8;
    m_Field08 = DAT_003841EC;
    t5 = DAT_003841D0;
    m_Field00 = 0;
    m_Field10 = t5;
    return this;
}
