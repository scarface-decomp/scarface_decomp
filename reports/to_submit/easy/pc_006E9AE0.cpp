// bin: pc
// va: 0x006E9AE0
// tool: the portal's starter code (no AI)
// content::LoadInventory::vfunc_03 (0x006E9AE0, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    void sub_006E9160();
    void sub_006EA020();
};

extern "C" char DAT_0073523C[];
extern "C" char DAT_007723EC[];
extern "C" void __cdecl sub_0043CE70(int);
extern "C" void __cdecl sub_006E9810(int);

namespace content {

class LoadInventory
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LoadInventory* vfunc_03(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

LoadInventory* LoadInventory::vfunc_03(int a1)
{
    int t1, t5;

    t1 = m_Field08;
    *(int*)this = (int)DAT_007723EC;
    if (m_Field08) {
        ((Object*)t1)->sub_006EA020();
        ((Object*)t1)->sub_006E9160();
        sub_0043CE70(t1);
    }
    t5 = m_Field0C;
    if (m_Field0C) {
        ((Object*)t5)->vfunc_01();
    }
    *(int*)this = (int)DAT_0073523C;
    if (a1 & 1) {
        sub_006E9810((int)this);
    }
    return this;
}

}
