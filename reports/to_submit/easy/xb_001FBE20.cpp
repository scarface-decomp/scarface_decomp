// bin: xb
// va: 0x001FBE20
// tool: the portal's starter code (no AI)
// ExplosionTemplate::vfunc_04 (0x001FBE20, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field28
{
    void sub_000216D0();
};

extern "C" void __stdcall sub_0002B700(int);

class ExplosionTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    void sub_001FBB90();
    void sub_001FBCA0();
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
    char m_pad23[0x5];
    Field28 m_Field28; // +0x28
};

void ExplosionTemplate::vfunc_04(int a1)
{
    sub_0002B700(a1);
    m_Field28.sub_000216D0();
    if (m_Field22) {
        sub_001FBB90();
        sub_001FBCA0();
    }
}
