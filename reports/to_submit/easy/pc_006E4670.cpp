// bin: pc
// va: 0x006E4670
// tool: the portal's starter code (no AI)
// sub_006E4670 (0x006E4670, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771DA4[];
extern "C" void __stdcall sub_006E4610(int);

class Class_006E4670
{
public:
    Class_006E4670* sub_006E4670(int a1, int a2, bool a3);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    bool m_Field10; // +0x10
};

Class_006E4670* Class_006E4670::sub_006E4670(int a1, int a2, bool a3)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771DA4;
    m_Field0C = a2;
    m_Field10 = a3;
    ((Object*)a2)->sub_006DEC00();
    return this;
}
