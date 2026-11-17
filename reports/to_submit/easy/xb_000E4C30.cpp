// bin: xb
// va: 0x000E4C30
// tool: the portal's starter code (no AI)
// DramaticCameraAction::vfunc_12 (0x000E4C30, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_001535E0();
    int sub_002722C0();
};

extern "C" int DAT_0048A218;

class DramaticCameraAction
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12(int a1);
};

int DramaticCameraAction::vfunc_12(int a1)
{
    return !((Object*)((Object*)DAT_0048A218)->sub_002722C0())->sub_001535E0();
}
