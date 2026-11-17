// bin: xb
// va: 0x000C0380
// tool: the portal's starter code (no AI)
// sub_000C0380 (0x000C0380, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;
extern "C" float DAT_003A48B4;
extern "C" float DAT_003D1058;

class Class_000C0380
{
public:
    void sub_000C0380();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
};

void Class_000C0380::sub_000C0380()
{
    if (m_Field00 > DAT_003A48B4) {
        m_Field04 = DAT_003D1058 / m_Field00;
        return;
    }
    m_Field04 = DAT_0039D664;
}
