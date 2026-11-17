// bin: xb
// va: 0x000A3440
// tool: the portal's starter code (no AI)
// sub_000A3440 (0x000A3440, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D584;

class Class_000A3440
{
public:
    int sub_000A3440();
    char m_pad00[0x4];
    float m_Field04; // +0x04
};

int Class_000A3440::sub_000A3440()
{
    if (m_Field04 > DAT_0039D584) {
        return 1;
    }
    return 0;
}
