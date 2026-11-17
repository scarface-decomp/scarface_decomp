// bin: proto
// va: 0x000B67C0
// tool: the portal's starter code (no AI)
// sub_000B67C0 (0x000B67C0, 87 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field40
{
    void sub_000B63E0(int, int);
};

struct Field54
{
    void sub_000B6540(int, int);
};

extern "C" int __cdecl sub_00028120(int);

class Class_000B67C0
{
public:
    void sub_000B67C0();
    char m_pad00[0x4];
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x34];
    Field40 m_Field40; // +0x40
    char m_pad41[0x13];
    Field54 m_Field54; // +0x54
    char m_pad55[0x17];
    Field54 m_Field6C; // +0x6C
};

void Class_000B67C0::sub_000B67C0()
{
    if (m_Field08) {
        m_Field40.sub_000B63E0(m_Field08, sub_00028120(m_Field04));
        m_Field54.sub_000B6540(m_Field08, sub_00028120(m_Field04));
        m_Field6C.sub_000B6540(m_Field08, sub_00028120(m_Field04));
    }
}
