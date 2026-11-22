// bin: proto
// va: 0x00147C20
// what: Asks the object kept at +0x188 a yes/no question; the answer is no when there is none.
// tool: Claude Opus 5.5 (transplanted from xb:0x001DE1B0, nearest by portal/tools/similar.py)
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
    return 0;
}