// bin: pc
// va: 0x006E4380
// tool: the portal's starter code (no AI)
// core::Request::vfunc_00 (0x006E4380, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" char DAT_00771C98[];
extern "C" char DAT_0085CDDC[];
extern "C" int DAT_0085CDF4;
extern "C" void __cdecl sub_006DF070(int);
extern "C" void __cdecl sub_006DF080(int);

namespace core {

class Request
{
public:
    virtual Request* vfunc_00(int a1);
};

Request* Request::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00771C98;
    if (a1 & 1) {
        sub_006DF080((int)DAT_0085CDDC);
        ((Object*)DAT_0085CDF4)->vfunc_05((int)this);
        sub_006DF070((int)DAT_0085CDDC);
    }
    return this;
}

}
