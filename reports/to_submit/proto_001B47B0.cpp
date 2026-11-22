// bin: proto
// va: 0x001B47B0
// what: Fills in the script system's description of the StatePropDragTemplate class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x00024510, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00417F0C;
extern "C" int DAT_00417F10;
extern "C" char DAT_00417DC0[];
extern "C" char DAT_00417DD4[];
extern "C" char DAT_004179C0[];
extern "C" int DAT_004179E4;
extern "C" void __cdecl sub_000660D0(int, int);
extern "C" void __cdecl sub_00069130(int, int, int, int, int, int, int, int, int);

class StatePropDragTemplate;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<StatePropDragTemplate>::vfunc_02()
{
    sub_000660D0(DAT_004179E4, DAT_00417F0C);
    DAT_00417F10 = (int)DAT_004179C0;
    sub_00069130((int)DAT_00417DD4, 6, 0, 0, 36, 0, 0, 0, 0);
    sub_00069130((int)DAT_00417DC0, 6, 0, 0, 40, 0, 0, 0, 0);
}