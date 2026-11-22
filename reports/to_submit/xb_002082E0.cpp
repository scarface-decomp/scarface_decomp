// bin: xb
// va: 0x002082E0
// what: Fills in the script system's description of the VehicleFlappingJointProperties class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x00024510, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004477E8;
extern "C" int DAT_004477EC;
extern "C" char DAT_00445F78[];
extern "C" char DAT_00445F88[];
extern "C" char DAT_0041BDC0[];
extern "C" int DAT_0041BDE0;
extern "C" void __cdecl sub_00070520(int, int);
extern "C" void __cdecl sub_00073780(int, int, int, int, int, int, int, int, int);

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
    sub_00070520(DAT_0041BDE0, DAT_004477E8);
    DAT_004477EC = (int)DAT_0041BDC0;
    sub_00073780((int)DAT_00445F88, 16, 0, 0, 40, 0, 0, 0, 0);
    sub_00073780((int)DAT_00445F78, 16, 0, 0, 56, 0, 0, 0, 0);
}