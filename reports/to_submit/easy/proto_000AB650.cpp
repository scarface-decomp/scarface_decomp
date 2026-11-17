// bin: proto
// va: 0x000AB650
// tool: the portal's starter code (no AI)
// sub_000AB650 (0x000AB650, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD94;

class Class_000AB650
{
public:
    int sub_000AB650();
    char m_pad00[0x50];
    float m_Field50; // +0x50
};

int Class_000AB650::sub_000AB650()
{
    if (m_Field50 > DAT_0037CD94) {
        return 1;
    }
    return 0;
}
