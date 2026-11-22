// bin: xb
// va: 0x000CF800
// what: Asks the object kept at +0x50 a yes/no question; the answer is no when there is none.
// tool: Claude Opus 5.5 (transplanted from xb:0x001DE1B0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00163DB0();
};

class Class_000CF800
{
public:
    bool sub_000CF800();
    char m_pad00[0x50];
    int m_Field50; // +0x50
};

bool Class_000CF800::sub_000CF800()
{
    int t1;

    t1 = m_Field50;
    if (m_Field50) {
        return ((Object*)t1)->sub_00163DB0();
    }
    return 0;
}