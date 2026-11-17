// bin: pc
// va: 0x006E43C0
// tool: the portal's starter code (no AI)
// sub_006E43C0 (0x006E43C0, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
};

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771C98[];
extern "C" char DAT_00771CB8[];
extern "C" void __cdecl sub_006DEC00(void);

class Class_006E43C0
{
public:
    Class_006E43C0* sub_006E43C0(int a1, int a2);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    Field0C* m_Field0C; // +0x0C
};

Class_006E43C0* Class_006E43C0::sub_006E43C0(int a1, int a2)
{
    m_Field00 = (int)DAT_00771C98;
    m_Field04 = 0;
    ::sub_006DEC00();
    m_Field00 = (int)DAT_00771CB8;
    m_Field08 = a1;
    m_Field0C = (Field0C*)a2;
    ((Object*)a2)->sub_006DEC00();
    m_Field0C->vfunc_00();
    return this;
}
