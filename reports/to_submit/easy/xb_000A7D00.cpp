// bin: xb
// va: 0x000A7D00
// tool: the portal's starter code (no AI)
// sub_000A7D00 (0x000A7D00, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_000A7D00
{
public:
    void sub_000A7D00();
    char m_pad00[0x4];
    int m_Field04; // +0x04
    char m_pad08[0x350];
    bool m_Field358; // +0x358
};

void Class_000A7D00::sub_000A7D00()
{
    int t1;

    if (m_Field358) {
        m_Field358 = false;
    }
    t1 = m_Field04;
    if (m_Field04) {
        ((Object*)t1)->vfunc_01();
        m_Field04 = 0;
    }
}
