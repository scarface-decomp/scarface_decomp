// bin: xb
// va: 0x000B5C90
// tool: the portal's starter code (no AI)
// sub_000B5C90 (0x000B5C90, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;

class Class_000B5C90
{
public:
    int sub_000B5C90();
    char m_pad00[0x10];
    float m_Field10; // +0x10
};

int Class_000B5C90::sub_000B5C90()
{
    if (DAT_0039D664 > m_Field10) {
        return 1;
    }
    return 0;
}
