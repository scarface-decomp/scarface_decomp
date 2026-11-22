// bin: pc
// va: 0x00703560
// what: 
// tool: the portal's starter code (no AI)

// sub_00703560 (PC 0x00703560, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007747EC[];
extern "C" void __cdecl sub_0065C9B0(void);
extern "C" void __cdecl sub_00704770(int);

class Class_00703560
{
public:
    Class_00703560* sub_00703560(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

Class_00703560* Class_00703560::sub_00703560(int a1)
{
    sub_0065C9B0();
    m_Field00 = (int)DAT_007747EC;
    m_Field18 = a1;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field14 = 0;
    sub_00704770(a1);
    return this;
}
