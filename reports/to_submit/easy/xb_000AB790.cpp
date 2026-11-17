// bin: xb
// va: 0x000AB790
// tool: the portal's starter code (no AI)
// sub_000AB790 (0x000AB790, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int);
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09(int);
};

extern "C" int __cdecl sub_00048B50(int);

class Class_000AB790
{
public:
    void sub_000AB790();
    char m_pad00[0x14];
    int m_Field14; // +0x14
};

void Class_000AB790::sub_000AB790()
{
    int t1, t2;

    t1 = m_Field14;
    if (m_Field14) {
        t2 = sub_00048B50(t1);
        if (t2) {
            ((Object*)t2)->vfunc_09(1);
            ((Object*)t2)->vfunc_06(0);
        }
    }
}
