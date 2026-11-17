// bin: pc
// va: 0x006E01E0
// tool: the portal's starter code (no AI)
// core::String::vfunc_06 (0x006E01E0, 34 bytes)
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
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual int vfunc_08();
};

namespace core {

class String
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1);
    virtual void vfunc_07(int);
};

void String::vfunc_06(int a1)
{
    if (a1) {
        if (a1 == (int)this) goto L_1E;
        vfunc_07(((Object*)a1)->vfunc_08());
    }
L_1E:
    ;
}

}
