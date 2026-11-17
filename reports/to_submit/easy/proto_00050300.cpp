// bin: proto
// va: 0x00050300
// tool: the portal's starter code (no AI)
// renderer::SkidmarkPrimitive::vfunc_08 (0x00050300, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
    int sub_00133AD0();
};

extern "C" char DAT_0044A59C[];
extern "C" bool DAT_0044A5EC;
extern "C" int __cdecl sub_00133750(void);

namespace renderer {

class SkidmarkPrimitive
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
};

void SkidmarkPrimitive::vfunc_08()
{
    int r_edi, r_esi;

    if (DAT_0044A5EC) {
        r_edi = ((Object*)sub_00133750())->sub_00133AD0();
        r_esi = 0;
        do {
            ((Object*)*(int*)(((int)DAT_0044A59C) + r_esi))->vfunc_00(r_edi);
            r_esi += 4;
        } while ((unsigned int)r_esi < (unsigned int)32);
    }
}

}
