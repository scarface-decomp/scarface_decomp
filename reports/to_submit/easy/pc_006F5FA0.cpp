// bin: pc
// va: 0x006F5FA0
// tool: the portal's starter code (no AI)
// sub_006F5FA0 (0x006F5FA0, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_006F2C00(int);
};

struct Object
{
    void sub_006EE060();
    void sub_006EE080();
};

class Class_006F5FA0
{
public:
    void sub_006F5FA0(int a1);
    char m_pad00[0x14];
    Field14 m_Field14; // +0x14
    char m_pad15[0x1F];
    unsigned char m_Field34; // +0x34
    unsigned char m_Field35; // +0x35
};

void Class_006F5FA0::sub_006F5FA0(int a1)
{
    m_Field14.sub_006F2C00(a1 + 16);
    if (m_Field35) {
        ((Object*)*(int*)(a1 + 32))->sub_006EE060();
    }
    if (m_Field34) {
        ((Object*)*(int*)(a1 + 32))->sub_006EE080();
    }
}
