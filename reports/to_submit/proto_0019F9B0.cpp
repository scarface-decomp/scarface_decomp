// bin: proto
// va: 0x0019F9B0
// what: Fills in the script system's description of the ZoneSoundObject class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x00024510, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00415328;
extern "C" int DAT_0041532C;
extern "C" char DAT_004152AC[];
extern "C" char DAT_004152BC[];
extern "C" char DAT_003F6D24[];
extern "C" int DAT_003F6D48;
extern "C" void __cdecl sub_000660D0(int, int);
extern "C" void __cdecl sub_00069130(int, int, int, int, int, int, int, int, int);

class ZoneSoundObject;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<ZoneSoundObject>::vfunc_02()
{
    sub_000660D0(DAT_003F6D48, DAT_00415328);
    DAT_0041532C = (int)DAT_003F6D24;
    sub_00069130((int)DAT_004152BC, 8, 0, 0, 52, 0, 0, 0, 0);
    sub_00069130((int)DAT_004152AC, 8, 0, 0, 56, 0, 0, 0, 0);
}