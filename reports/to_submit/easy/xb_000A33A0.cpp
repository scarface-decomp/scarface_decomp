// bin: xb
// va: 0x000A33A0
// tool: the portal's starter code (no AI)
// sub_000A33A0 (0x000A33A0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A4A84;

class Class_000A33A0
{
public:
    int sub_000A33A0();
    char m_pad00[0x20];
    float m_Field20; // +0x20
};

int Class_000A33A0::sub_000A33A0()
{
    if (m_Field20 > DAT_003A4A84) {
        return 1;
    }
    return 0;
}
