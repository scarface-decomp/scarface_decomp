// bin: proto
// va: 0x001C0930
// tool: the portal's starter code (no AI)
// ExplosionTemplate::vfunc_05 (0x001C0930, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field28
{
    void sub_0001F4E0();
};

extern "C" void __stdcall sub_00028C40(int);

class ExplosionTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    void sub_001C06A0();
    void sub_001C07B0();
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
    char m_pad23[0x5];
    Field28 m_Field28; // +0x28
};

void ExplosionTemplate::vfunc_05(int a1)
{
    sub_00028C40(a1);
    m_Field28.sub_0001F4E0();
    if (m_Field22) {
        sub_001C06A0();
        sub_001C07B0();
    }
}
