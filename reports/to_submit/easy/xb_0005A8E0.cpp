// bin: xb
// va: 0x0005A8E0
// tool: the portal's starter code (no AI)
// renderer::SkidmarkPrimitive::vfunc_08 (0x0005A8E0, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
    int sub_0014FF20();
};

extern "C" char DAT_00475990[];
extern "C" bool DAT_00475A80;
extern "C" int __cdecl sub_0014FFE0(void);

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

    if (DAT_00475A80) {
        r_edi = ((Object*)sub_0014FFE0())->sub_0014FF20();
        r_esi = 0;
        do {
            ((Object*)*(int*)(((int)DAT_00475990) + r_esi))->vfunc_00(r_edi);
            r_esi += 4;
        } while ((unsigned int)r_esi < (unsigned int)192);
    }
}

}
