// bin: proto
// va: 0x001EBBA0
// tool: the portal's starter code (no AI)
// GameLoadingManager::vfunc_03 (0x001EBBA0, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001ECB40(int);
};

extern "C" char DAT_003AB5A4[];
extern "C" bool DAT_00462F8B;
extern "C" int DAT_00462F98;
extern "C" void __cdecl sub_00065ED0(int, int, int, int, int);
extern "C" void __cdecl sub_001B7A10(void);
extern "C" void __cdecl sub_001ECBC0(void);

class GameLoadingManager
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int a1, int a2);
    void sub_001EB9B0();
};

int GameLoadingManager::vfunc_03(int a1, int a2)
{
    sub_001B7A10();
    if (DAT_00462F8B) {
        sub_001ECBC0();
        return 1;
    }
    sub_001EB9B0();
    ((Object*)DAT_00462F98)->sub_001ECB40(0);
    sub_00065ED0((int)DAT_003AB5A4, 0, 0, 0, -1);
    return 1;
}
