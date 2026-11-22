// bin: proto
// va: 0x000BD400
// what: Updates every item in the list at +0xC4 and checks whether all of them have reached state 2.
// tool: Claude Opus 5.5 (transplanted from xb:0x000CD9E0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000BDFE0();
};

class Class_000BD400
{
public:
    void sub_000BD400();
    char m_pad00[0xB4];
    int m_FieldB4; // +0xB4
    int m_FieldB8; // +0xB8
    char m_padBC[0x8];
    int m_FieldC4; // +0xC4
    int m_FieldC8; // +0xC8
};

void Class_000BD400::sub_000BD400()
{
    int r_eax, r_ebp, r_ebx, r_esi;

    r_eax = 0;
    r_esi = m_FieldC4;
    r_ebx = m_FieldC8;
    r_ebp = 0;
    if (r_esi != r_ebx) {
        do {
            ((Object*)*(int*)r_esi)->sub_000BDFE0();
            r_eax = *(int*)r_esi;
            if (*(int*)(r_eax + 20) == 2) {
                r_ebp += 1;
            }
            r_esi += 4;
        } while (r_esi != r_ebx);
    }
    if (r_ebp == ((m_FieldC8 - m_FieldC4) >> 2)) {
        m_FieldB4 = 4;
        m_FieldB8 = 1;
    }
    return;
}