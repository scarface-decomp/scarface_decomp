// bin: proto
// va: 0x001AE1F0
// what: Fills in the script system's description of the GangNestSpawnObject class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from xb:0x000268A0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00417128;
extern "C" int DAT_0041712C;
extern "C" char DAT_00415A08[];
extern "C" char DAT_00415A18[];
extern "C" char DAT_004170D8[];
extern "C" int DAT_004170FC;
extern "C" void __cdecl sub_000660D0(int, int);
extern "C" void __cdecl sub_00069130(int, int, int, int, int, int, int, int, int);

class GangNestSpawnObject;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<GangNestSpawnObject>::vfunc_02()
{
    sub_000660D0(DAT_004170FC, DAT_00417128);
    DAT_0041712C = (int)DAT_004170D8;
    sub_00069130((int)DAT_00415A18, 2, 0, 0, 72, 0, 0, 0, 0);
    sub_00069130((int)DAT_00415A08, 2, 0, 0, 76, 0, 0, 0, 0);
}