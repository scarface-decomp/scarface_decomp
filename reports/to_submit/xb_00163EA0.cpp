// bin: xb
// va: 0x00163EA0
// what: Asks the object kept at +0x1AC a yes/no question; the answer is no when there is none.
// tool: Claude Opus 5.5 (transplanted from xb:0x001DE1B0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_000CF820();
};

class Class_00163EA0
{
public:
    bool sub_00163EA0();
    char m_pad00[0x1AC];
    int m_Field1AC; // +0x1AC
};

bool Class_00163EA0::sub_00163EA0()
{
    int t1;

    t1 = m_Field1AC;
    if (m_Field1AC) {
        return ((Object*)t1)->sub_000CF820();
    }
    return 0;
}