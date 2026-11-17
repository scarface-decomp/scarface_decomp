// bin: proto
// va: 0x000B8E90
// tool: the portal's starter code (no AI)
// sub_000B8E90 (0x000B8E90, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field5C
{
    void sub_000B83E0(int);
    void sub_000B84A0(int, int, int, int);
};

class Class_000B8E90
{
public:
    void sub_000B8E90(bool a1, bool a2);
    int sub_000B8BB0();
    char m_pad00[0x5C];
    Field5C* m_Field5C; // +0x5C
    int m_Field60; // +0x60
    int m_Field64; // +0x64
    char m_pad68[0x8];
    char m_Field70; // +0x70
    char m_Field71; // +0x71
};

void Class_000B8E90::sub_000B8E90(bool a1, bool a2)
{
    m_Field70 = a1;
    if (!a2) {
        m_Field5C->sub_000B83E0(0);
        m_Field60 = 2;
        m_Field71 = 0;
        m_Field5C->sub_000B84A0(m_Field70, m_Field71, m_Field64, sub_000B8BB0());
    }
}
