// bin: proto
// va: 0x000BF140
// tool: the portal's starter code (no AI)
// sub_000BF140 (0x000BF140, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;

class Class_000BF140
{
public:
    void sub_000BF140();
    char m_pad00[0x4C];
    float m_Field4C; // +0x4C
};

void Class_000BF140::sub_000BF140()
{
    m_Field4C = DAT_0037CE50;
}
