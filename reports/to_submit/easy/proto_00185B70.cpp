// bin: proto
// va: 0x00185B70
// tool: the portal's starter code (no AI)
// sub_00185B70 (0x00185B70, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0016D4C0(int);
    void sub_0016D670(int, int, int);
};

extern "C" char DAT_0039C200[];
extern "C" int DAT_0045E044;
extern "C" int __cdecl sub_00065830(int, int);

class Class_00185B70
{
public:
    void sub_00185B70();
    char m_pad00[0x44];
    int m_Field44; // +0x44
};

void Class_00185B70::sub_00185B70()
{
    int t1, t4;

    t1 = m_Field44;
    if (m_Field44 > -1) {
        if (t1 >= 6) goto L_42;
        ((Object*)DAT_0045E044)->sub_0016D4C0(-1);
        t4 = DAT_0045E044;
        ((Object*)t4)->sub_0016D670(8, sub_00065830((int)DAT_0039C200, m_Field44), 0);
    }
L_42:
    ;
}
