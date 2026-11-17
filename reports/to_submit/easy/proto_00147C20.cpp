// bin: proto
// va: 0x00147C20
// tool: the portal's starter code (no AI)
// sub_00147C20 (0x00147C20, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_000BEFF0();
};

class Class_00147C20
{
public:
    bool sub_00147C20();
    char m_pad00[0x188];
    int m_Field188; // +0x188
};

bool Class_00147C20::sub_00147C20()
{
    int t1;

    t1 = m_Field188;
    if (m_Field188) {
        return ((Object*)t1)->sub_000BEFF0();
    }
    return false;
}
