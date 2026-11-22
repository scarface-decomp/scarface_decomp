// bin: proto
// va: 0x000B2A00
// what: 
// tool: the portal's starter code (no AI)

// sub_000B2A00 (Proto 0x000B2A00, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;
extern "C" float DAT_0037D4D0;
extern "C" float DAT_003850D4;

class Class_000B2A00
{
public:
    void sub_000B2A00();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
};

void Class_000B2A00::sub_000B2A00()
{
    if (m_Field00 > DAT_0037D4D0) {
        m_Field04 = DAT_003850D4 / m_Field00;
        return;
    }
    m_Field04 = DAT_0037CE50;
}
