// bin: pc
// va: 0x006E4B00
// tool: the portal's starter code (no AI)
// sub_006E4B00 (0x006E4B00, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F204;
extern "C" char DAT_00771F64[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4980(int);

class Class_006E4B00
{
public:
    Class_006E4B00* sub_006E4B00(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0xC];
    bool m_Field1C; // +0x1C
};

Class_006E4B00* Class_006E4B00::sub_006E4B00(int a1, int a2)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00771F64;
    sub_006DEC00();
    ((void (__cdecl*)(int, int, int))DAT_0072F204)((int)(&m_Field0C), a2, 16);
    m_Field1C = false;
    return this;
}
