// bin: proto
// va: 0x001CAEE0
// what: Fills in the script system's description of the VehicleSimpleLocomotionProperties class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x00024510, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0041F658;
extern "C" int DAT_0041F65C;
extern "C" char DAT_0041EFD0[];
extern "C" char DAT_0041EFF0[];
extern "C" char DAT_003F6D24[];
extern "C" int DAT_003F6D48;
extern "C" void __cdecl sub_000660D0(int, int);
extern "C" void __cdecl sub_00069130(int, int, int, int, int, int, int, int, int);

class VehicleSimpleLocomotionProperties;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<VehicleSimpleLocomotionProperties>::vfunc_02()
{
    sub_000660D0(DAT_003F6D48, DAT_0041F658);
    DAT_0041F65C = (int)DAT_003F6D24;
    sub_00069130((int)DAT_0041EFF0, 6, 0, 0, 36, 0, 0, 0, 0);
    sub_00069130((int)DAT_0041EFD0, 6, 0, 0, 44, 0, 0, 0, 0);
}