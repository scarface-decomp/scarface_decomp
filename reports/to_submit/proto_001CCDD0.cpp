// bin: proto
// va: 0x001CCDD0
// what: Fills in the script system's description of the VehicleFlappingJointProperties class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x00024510, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0042118C;
extern "C" int DAT_00421190;
extern "C" char DAT_0041F914[];
extern "C" char DAT_0041F924[];
extern "C" char DAT_003F6D24[];
extern "C" int DAT_003F6D48;
extern "C" void __cdecl sub_000660D0(int, int);
extern "C" void __cdecl sub_00069130(int, int, int, int, int, int, int, int, int);

class VehicleFlappingJointProperties;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<VehicleFlappingJointProperties>::vfunc_02()
{
    sub_000660D0(DAT_003F6D48, DAT_0042118C);
    DAT_00421190 = (int)DAT_003F6D24;
    sub_00069130((int)DAT_0041F924, 8, 0, 0, 40, 0, 0, 0, 0);
    sub_00069130((int)DAT_0041F914, 8, 0, 0, 56, 0, 0, 0, 0);
}