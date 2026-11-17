// bin: proto
// va: 0x000974D0
// tool: the portal's starter code (no AI)
// sub_000974D0 (0x000974D0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD94;

class Class_000974D0
{
public:
    int sub_000974D0();
    char m_pad00[0x4];
    float m_Field04; // +0x04
};

int Class_000974D0::sub_000974D0()
{
    if (m_Field04 > DAT_0037CD94) {
        return 1;
    }
    return 0;
}
