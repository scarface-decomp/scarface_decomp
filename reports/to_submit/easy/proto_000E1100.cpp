// bin: proto
// va: 0x000E1100
// tool: the portal's starter code (no AI)
// sub_000E1100 (0x000E1100, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00147EB0(int);
};

extern "C" int __cdecl sub_00028120(int);

class Class_000E1100
{
public:
    void sub_000E1100(bool a1);
    char m_pad00[0x84];
    int m_Field84; // +0x84
    char m_pad88[0x56A];
    bool m_Field5F2; // +0x5F2
};

void Class_000E1100::sub_000E1100(bool a1)
{
    m_Field5F2 = a1;
    if (!a1) {
        ((Object*)sub_00028120(m_Field84))->sub_00147EB0(0);
    }
}
