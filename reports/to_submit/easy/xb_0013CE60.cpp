// bin: xb
// va: 0x0013CE60
// tool: the portal's starter code (no AI)
// sub_0013CE60 (0x0013CE60, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D584;

class Class_0013CE60
{
public:
    int sub_0013CE60();
    char m_pad00[0x138];
    float m_Field138; // +0x138
};

int Class_0013CE60::sub_0013CE60()
{
    if (m_Field138 > DAT_0039D584) {
        return 1;
    }
    return 0;
}
