// bin: pc
// va: 0x006E0090
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_04 (PC 0x006E0090, 36 bytes)
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
    virtual bool vfunc_04(int a1);
    virtual bool vfunc_05(int);
};

bool String::vfunc_04(int a1)
{
    if (a1) {
        return vfunc_05(((Object*)a1)->vfunc_08());
    }
    return false;
}

}
