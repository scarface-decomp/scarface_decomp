// bin: xb
// va: 0x000A33F0
// tool: the portal's starter code (no AI)
// sub_000A33F0 (0x000A33F0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;

class Class_000A33F0
{
public:
    void sub_000A33F0();
    char m_pad00[0x4];
    float m_Field04; // +0x04
};

void Class_000A33F0::sub_000A33F0()
{
    m_Field04 = DAT_0039D65C;
}
