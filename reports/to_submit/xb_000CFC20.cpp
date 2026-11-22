// bin: xb
// va: 0x000CFC20
// what: Asks the object kept at +0x17C a yes/no question; the answer is no when there is none.
// tool: Claude Opus 5.5 (transplanted from xb:0x001DE1B0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00021EE0();
};

class Class_000CFC20
{
public:
    bool sub_000CFC20();
    char m_pad00[0x17C];
    int m_Field17C; // +0x17C
};

bool Class_000CFC20::sub_000CFC20()
{
    int t1;

    t1 = m_Field17C;
    if (m_Field17C) {
        return ((Object*)t1)->sub_00021EE0();
    }
    return 0;
}