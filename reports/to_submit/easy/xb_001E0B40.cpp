// bin: xb
// va: 0x001E0B40
// tool: the portal's starter code (no AI)
// sub_001E0B40 (0x001E0B40, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D584;

class Class_001E0B40
{
public:
    int sub_001E0B40();
    char m_pad00[0x120];
    float m_Field120; // +0x120
};

int Class_001E0B40::sub_001E0B40()
{
    if (m_Field120 > DAT_0039D584) {
        return 1;
    }
    return 0;
}
