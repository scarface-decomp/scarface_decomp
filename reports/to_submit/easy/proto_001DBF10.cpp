// bin: proto
// va: 0x001DBF10
// tool: the portal's starter code (no AI)
// sub_001DBF10 (0x001DBF10, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    void sub_0009ED40();
};

struct Field48
{
    void sub_000A14C0();
};

struct Object
{
    void sub_00029460();
    void sub_0008D4C0(int);
};

extern "C" int __cdecl sub_00028120(int);

class Class_001DBF10
{
public:
    void sub_001DBF10();
    char m_pad00[0x1C];
    int m_Field1C; // +0x1C
    char m_pad20[0x10];
    Field30 m_Field30; // +0x30
    char m_pad31[0x13];
    bool m_Field44; // +0x44
    char m_pad45[0x3];
    Field48 m_Field48; // +0x48
};

void Class_001DBF10::sub_001DBF10()
{
    int r_edi, r_esi, t3;

    if (m_Field44) {
        m_Field30.sub_0009ED40();
        r_esi = (int)(&m_Field1C);
        r_edi = 5;
        do {
            t3 = sub_00028120(*(int*)r_esi);
            if (t3) {
                ((Object*)t3)->sub_00029460();
            }
            ((Object*)r_esi)->sub_0008D4C0(0);
            r_esi += 4;
            r_edi -= 1;
        } while (r_edi);
        m_Field48.sub_000A14C0();
        m_Field44 = false;
    }
}
