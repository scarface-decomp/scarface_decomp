// bin: pc
// va: 0x006E0570
// tool: the portal's starter code (no AI)
// sub_006E0570 (0x006E0570, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0073523C[];
extern "C" char DAT_00736074[];
extern "C" char DAT_00771A50[];
extern "C" char DAT_00771A5C[];
extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);

class Class_006E0570
{
public:
    void sub_006E0570();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x4];
    int m_Field10; // +0x10
};

void Class_006E0570::sub_006E0570()
{
    int t1;

    t1 = m_Field10;
    m_Field00 = (int)DAT_00771A5C;
    m_Field04 = (int)DAT_00771A50;
    if (m_Field10) {
        sub_006DC430(m_Field08, t1);
        m_Field10 = 0;
    }
    DAT_007F5A70 = m_Field08;
    m_Field04 = (int)DAT_00736074;
    m_Field00 = (int)DAT_0073523C;
}
