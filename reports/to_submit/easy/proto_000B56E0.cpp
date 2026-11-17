// bin: proto
// va: 0x000B56E0
// tool: the portal's starter code (no AI)
// sub_000B56E0 (0x000B56E0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_00384640;

class Class_000B56E0
{
public:
    void sub_000B56E0();
    char m_pad00[0x4];
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

void Class_000B56E0::sub_000B56E0()
{
    m_Field08 = m_Field04 * DAT_00384640;
}
