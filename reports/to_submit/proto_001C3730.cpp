// bin: proto
// va: 0x001C3730
// what: Fills in the script system's description of the MortarWeaponTemplate class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x00024510, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0041A9A0;
extern "C" int DAT_0041A9A4;
extern "C" char DAT_0041A380[];
extern "C" char DAT_0041A3A0[];
extern "C" char DAT_0041A924[];
extern "C" int DAT_0041A948;
extern "C" void __cdecl sub_000660D0(int, int);
extern "C" void __cdecl sub_00069130(int, int, int, int, int, int, int, int, int);

class MortarWeaponTemplate;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<MortarWeaponTemplate>::vfunc_02()
{
    sub_000660D0(DAT_0041A948, DAT_0041A9A0);
    DAT_0041A9A4 = (int)DAT_0041A924;
    sub_00069130((int)DAT_0041A3A0, 8, 0, 0, 216, 0, 0, 0, 0);
    sub_00069130((int)DAT_0041A380, 8, 0, 0, 220, 0, 0, 0, 0);
}