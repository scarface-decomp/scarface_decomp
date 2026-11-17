// bin: proto
// va: 0x000DDCB0
// tool: the portal's starter code (no AI)
// sub_000DDCB0 (0x000DDCB0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field238
{
    int sub_00056450();
    void sub_0007CD00(int);
    void sub_0007CD70();
};

class Class_000DDCB0
{
public:
    void sub_000DDCB0();
    char m_pad00[0x104];
    float m_Field104; // +0x104
    float m_Field108; // +0x108
    float m_Field10C; // +0x10C
    char m_pad110[0x128];
    Field238 m_Field238; // +0x238
};

void Class_000DDCB0::sub_000DDCB0()
{
    if (m_Field238.sub_00056450()) {
        m_Field238.sub_0007CD00(0);
        m_Field238.sub_0007CD70();
    }
    m_Field10C = 0.0f;
    m_Field108 = 0.0f;
    m_Field104 = 0.0f;
}
