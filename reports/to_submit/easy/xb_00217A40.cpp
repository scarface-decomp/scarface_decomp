// bin: xb
// va: 0x00217A40
// tool: the portal's starter code (no AI)
// sub_00217A40 (0x00217A40, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    void sub_000AADB0();
};

struct Field48
{
    void sub_000AE150();
};

struct Object
{
    void sub_0002BFA0();
    void sub_00098B90(int);
};

extern "C" int __cdecl sub_0002AC90(int);

class Class_00217A40
{
public:
    void sub_00217A40();
    char m_pad00[0x20];
    int m_Field20; // +0x20
    char m_pad24[0xC];
    Field30 m_Field30; // +0x30
    char m_pad31[0x13];
    bool m_Field44; // +0x44
    char m_pad45[0x3];
    Field48 m_Field48; // +0x48
};

void Class_00217A40::sub_00217A40()
{
    int r_edi, r_esi, t3;

    if (m_Field44) {
        m_Field30.sub_000AADB0();
        r_esi = (int)(&m_Field20);
        r_edi = 4;
        do {
            t3 = sub_0002AC90(*(int*)r_esi);
            if (t3) {
                ((Object*)t3)->sub_0002BFA0();
            }
            ((Object*)r_esi)->sub_00098B90(0);
            r_esi += 4;
            r_edi -= 1;
        } while (r_edi);
        m_Field48.sub_000AE150();
        m_Field44 = false;
    }
}
