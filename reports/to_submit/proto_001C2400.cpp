// bin: proto
// va: 0x001C2400
// what: Fills in the script system's description of the SkyTemplate class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x00024510, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00419A84;
extern "C" int DAT_00419A88;
extern "C" char DAT_00419A14[];
extern "C" char DAT_00419A20[];
extern "C" char DAT_003F6F68[];
extern "C" int DAT_003F6F8C;
extern "C" void __cdecl sub_000660D0(int, int);
extern "C" void __cdecl sub_00069130(int, int, int, int, int, int, int, int, int);

class SkyTemplate;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<SkyTemplate>::vfunc_02()
{
    sub_000660D0(DAT_003F6F8C, DAT_00419A84);
    DAT_00419A88 = (int)DAT_003F6F68;
    sub_00069130((int)DAT_00419A20, 8, 0, 0, 36, 0, 0, 0, 0);
    sub_00069130((int)DAT_00419A14, 8, 0, 0, 40, 0, 0, 0, 0);
}