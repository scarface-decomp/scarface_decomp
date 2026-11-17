// bin: pc
// va: 0x006E4760
// tool: the portal's starter code (no AI)
// sub_006E4760 (0x006E4760, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771DC4[];
extern "C" void __stdcall sub_006E4610(int);

class Class_006E4760
{
public:
    Class_006E4760* sub_006E4760(int a1, int a2, bool a3, int a4, int a5);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    bool m_Field10; // +0x10
    char m_pad11[0x3];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

Class_006E4760* Class_006E4760::sub_006E4760(int a1, int a2, bool a3, int a4, int a5)
{
    sub_006E4610(a1);
    m_Field0C = a2;
    m_Field00 = (int)DAT_00771DC4;
    m_Field10 = a3;
    m_Field14 = a4;
    m_Field18 = a5;
    ((Object*)a5)->sub_006DEC00();
    return this;
}
