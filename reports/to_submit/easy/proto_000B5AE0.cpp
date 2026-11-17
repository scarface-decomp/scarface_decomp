// bin: proto
// va: 0x000B5AE0
// tool: the portal's starter code (no AI)
// sub_000B5AE0 (0x000B5AE0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE60;

class Class_000B5AE0
{
public:
    void sub_000B5AE0();
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

void Class_000B5AE0::sub_000B5AE0()
{
    float t1;

    t1 = DAT_0037CE60;
    m_Field0C = 0;
    m_Field10 = t1;
}
