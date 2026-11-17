// bin: proto
// va: 0x0029CC20
// tool: the portal's starter code (no AI)
// sub_0029CC20 (0x0029CC20, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_0029CB70(int);
};

struct Object
{
    void sub_002916D0();
    void sub_002916F0();
};

class Class_0029CC20
{
public:
    void sub_0029CC20(int a1);
    char m_pad00[0x14];
    Field14 m_Field14; // +0x14
    char m_pad15[0x2B];
    bool m_Field40; // +0x40
    bool m_Field41; // +0x41
};

void Class_0029CC20::sub_0029CC20(int a1)
{
    m_Field14.sub_0029CB70(a1 + 16);
    if (m_Field41) {
        ((Object*)*(int*)(a1 + 32))->sub_002916D0();
    }
    if (m_Field40) {
        ((Object*)*(int*)(a1 + 32))->sub_002916F0();
    }
}
