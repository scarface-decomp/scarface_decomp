// bin: proto
// va: 0x000D2A20
// tool: the portal's starter code (no AI)
// DramaticCameraAction::vfunc_11 (0x000D2A20, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001337A0();
    bool sub_00138160();
};

extern "C" int __cdecl sub_00133750(void);

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
    virtual int vfunc_11(int a1);
};

int DramaticCameraAction::vfunc_11(int a1)
{
    return !((Object*)((Object*)sub_00133750())->sub_001337A0())->sub_00138160();
}
