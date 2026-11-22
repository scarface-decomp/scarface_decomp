// bin: proto
// va: 0x001CCE60
// what: Fills in the script system's description of the VehicleRenderMaskTemplate class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x00024510, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004211B8;
extern "C" int DAT_004211BC;
extern "C" char DAT_0041F938[];
extern "C" char DAT_0041F948[];
extern "C" char DAT_0041DF28[];
extern "C" int DAT_0041DF4C;
extern "C" void __cdecl sub_000660D0(int, int);
extern "C" void __cdecl sub_00069130(int, int, int, int, int, int, int, int, int);

class VehicleRenderMaskTemplate;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<VehicleRenderMaskTemplate>::vfunc_02()
{
    sub_000660D0(DAT_0041DF4C, DAT_004211B8);
    DAT_004211BC = (int)DAT_0041DF28;
    sub_00069130((int)DAT_0041F948, 8, 0, 0, 52, 0, 0, 0, 0);
    sub_00069130((int)DAT_0041F938, 8, 0, 0, 56, 0, 0, 0, 0);
}