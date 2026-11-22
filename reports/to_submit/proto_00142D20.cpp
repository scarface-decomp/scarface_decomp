// bin: proto
// va: 0x00142D20
// what: The first time only: sets a flag and tells a linked object to switch something on.
// tool: Claude Opus 5.5 (transplanted from xb:0x0015D530, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000C6C10(int);
};

class Class_00142D20
{
public:
    void sub_00142D20();
    char m_pad00[0xB8];
    int m_FieldB8; // +0xB8
    char m_padBC[0xE];
    bool m_FieldCA; // +0xCA
};

void Class_00142D20::sub_00142D20()
{
    int r_eax;

    r_eax = m_FieldCA;
    if (!((unsigned char)r_eax)) {
        r_eax = m_FieldB8;
        m_FieldCA = true;
        r_eax = ((Object*)*(int*)(*(int*)(r_eax + 392) + 384))->sub_000C6C10(1);
    }
}