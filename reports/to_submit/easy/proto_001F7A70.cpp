// bin: proto
// va: 0x001F7A70
// tool: the portal's starter code (no AI)
// sub_001F7A70 (0x001F7A70, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field18
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int);
};

extern "C" void __cdecl sub_001F8200(void);

class Class_001F7A70
{
public:
    void sub_001F7A70();
    char m_pad00[0x14];
    int m_Field14; // +0x14
    Field18* m_Field18; // +0x18
};

void Class_001F7A70::sub_001F7A70()
{
    sub_001F8200();
    if (m_Field14) {
        m_Field18->vfunc_06(0);
    }
}
