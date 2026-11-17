// bin: proto
// va: 0x000BBDB0
// tool: the portal's starter code (no AI)
// sub_000BBDB0 (0x000BBDB0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000BD360();
};

class Class_000BBDB0
{
public:
    unsigned short sub_000BBDB0();
    char m_pad00[0x8];
    int m_Field08; // +0x08
};

unsigned short Class_000BBDB0::sub_000BBDB0()
{
    int r_eax, t1;

    r_eax = 0;
    t1 = m_Field08;
    if (m_Field08) {
        return ((Object*)t1)->sub_000BD360();
    }
    r_eax |= 65535;
    return r_eax;
}
