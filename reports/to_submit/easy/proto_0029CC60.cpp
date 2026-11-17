// bin: proto
// va: 0x0029CC60
// tool: the portal's starter code (no AI)
// sub_0029CC60 (0x0029CC60, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_0029CBB0(int);
};

struct Object
{
    void sub_002916E0();
    void sub_00291700();
};

class Class_0029CC60
{
public:
    void sub_0029CC60(int a1);
    char m_pad00[0x14];
    Field14 m_Field14; // +0x14
    char m_pad15[0x2B];
    bool m_Field40; // +0x40
    bool m_Field41; // +0x41
};

void Class_0029CC60::sub_0029CC60(int a1)
{
    m_Field14.sub_0029CBB0(a1 + 16);
    if (m_Field41) {
        ((Object*)*(int*)(a1 + 32))->sub_002916E0();
    }
    if (m_Field40) {
        ((Object*)*(int*)(a1 + 32))->sub_00291700();
    }
}
