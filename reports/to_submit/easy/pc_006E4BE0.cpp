// bin: pc
// va: 0x006E4BE0
// tool: the portal's starter code (no AI)
// sub_006E4BE0 (0x006E4BE0, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F204;
extern "C" char DAT_00771FE4[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4980(int);

class Class_006E4BE0
{
public:
    Class_006E4BE0* sub_006E4BE0(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0xFC];
    bool m_Field10C; // +0x10C
};

Class_006E4BE0* Class_006E4BE0::sub_006E4BE0(int a1, int a2)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00771FE4;
    sub_006DEC00();
    ((void (__cdecl*)(int, int, int))DAT_0072F204)((int)(&m_Field0C), a2, 256);
    m_Field10C = false;
    return this;
}
