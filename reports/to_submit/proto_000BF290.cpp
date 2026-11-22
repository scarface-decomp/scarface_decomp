// bin: proto
// va: 0x000BF290
// what: Asks the object kept at +0x184 a yes/no question; the answer is no when there is none.
// tool: Claude Opus 5.5 (transplanted from xb:0x001DE1B0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_0001FCC0();
};

class Class_000BF290
{
public:
    bool sub_000BF290();
    char m_pad00[0x184];
    int m_Field184; // +0x184
};

bool Class_000BF290::sub_000BF290()
{
    int t1;

    t1 = m_Field184;
    if (m_Field184) {
        return ((Object*)t1)->sub_0001FCC0();
    }
    return 0;
}