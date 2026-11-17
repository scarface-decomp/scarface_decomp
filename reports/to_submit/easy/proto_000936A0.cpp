// bin: proto
// va: 0x000936A0
// tool: the portal's starter code (no AI)
// sub_000936A0 (0x000936A0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037F534;

class Class_000936A0
{
public:
    void sub_000936A0();
    char m_pad00[0x1C];
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    float m_Field28; // +0x28
};

void Class_000936A0::sub_000936A0()
{
    float t1;

    t1 = DAT_0037F534;
    m_Field20 = m_Field1C * t1;
    m_Field28 = m_Field24 * t1;
}
