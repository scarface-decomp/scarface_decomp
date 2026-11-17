// bin: proto
// va: 0x001BB390
// tool: the portal's starter code (no AI)
// Targeting::vfunc_10 (0x001BB390, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0008D4E0(int);
    void sub_001BF6E0();
};

extern "C" Object DAT_00462DD4;
extern "C" int DAT_00462DD8;
extern "C" int __cdecl sub_001BD8D0(void);

class Targeting
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10(int a1);
    char m_pad04[0x145];
    bool m_Field149; // +0x149
    bool m_Field14A; // +0x14A
};

void Targeting::vfunc_10(int a1)
{
    int t3;

    if (DAT_00462DD4.sub_0008D4E0(DAT_00462DD8)) {
        t3 = sub_001BD8D0();
        if (t3) {
            ((Object*)t3)->sub_001BF6E0();
        }
        m_Field149 = true;
        m_Field14A = true;
    }
}
