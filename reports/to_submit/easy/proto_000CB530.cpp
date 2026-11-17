// bin: proto
// va: 0x000CB530
// tool: the portal's starter code (no AI)
// sub_000CB530 (0x000CB530, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038583C[];
extern "C" void __cdecl sub_0001F660(void);

class Class_000CB530
{
public:
    Class_000CB530* sub_000CB530();
    int m_Field00; // +0x00
    char m_pad04[0xC];
    int m_Field10; // +0x10
    float m_Field14; // +0x14
};

Class_000CB530* Class_000CB530::sub_000CB530()
{
    sub_0001F660();
    m_Field00 = (int)DAT_0038583C;
    m_Field10 = 5;
    m_Field14 = 0.0f;
    return this;
}
