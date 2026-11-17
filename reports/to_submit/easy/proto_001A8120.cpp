// bin: proto
// va: 0x001A8120
// tool: the portal's starter code (no AI)
// sub_001A8120 (0x001A8120, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD94;

class Class_001A8120
{
public:
    int sub_001A8120();
    char m_pad00[0x114];
    float m_Field114; // +0x114
};

int Class_001A8120::sub_001A8120()
{
    if (m_Field114 > DAT_0037CD94) {
        return 1;
    }
    return 0;
}
