// bin: xb
// va: 0x000B8D90
// tool: the portal's starter code (no AI)
// sub_000B8D90 (0x000B8D90, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D584;

class Class_000B8D90
{
public:
    int sub_000B8D90();
    char m_pad00[0x50];
    float m_Field50; // +0x50
};

int Class_000B8D90::sub_000B8D90()
{
    if (m_Field50 > DAT_0039D584) {
        return 1;
    }
    return 0;
}
