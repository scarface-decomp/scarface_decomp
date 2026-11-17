// bin: pc
// va: 0x006E4400
// tool: the portal's starter code (no AI)
// core::CompletionEventRequest::vfunc_00 (0x006E4400, 74 bytes)
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
extern "C" char DAT_00771CB8[];
extern "C" char DAT_0085CDDC[];
extern "C" int DAT_0085CDF4;
extern "C" void __cdecl sub_006DF070(int);
extern "C" void __cdecl sub_006DF080(int);

namespace core {

class CompletionEventRequest
{
public:
    virtual CompletionEventRequest* vfunc_00(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

CompletionEventRequest* CompletionEventRequest::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field0C;
    *(int*)this = (int)DAT_00771CB8;
    ((Object*)t1)->vfunc_01();
    *(int*)this = (int)DAT_00771C98;
    if (a1 & 1) {
        sub_006DF080((int)DAT_0085CDDC);
        ((Object*)DAT_0085CDF4)->vfunc_05((int)this);
        sub_006DF070((int)DAT_0085CDDC);
    }
    return this;
}

}
