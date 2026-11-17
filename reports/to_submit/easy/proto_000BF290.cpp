// bin: proto
// va: 0x000BF290
// tool: the portal's starter code (no AI)
// sub_000BF290 (0x000BF290, 18 bytes)
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
    return false;
}
