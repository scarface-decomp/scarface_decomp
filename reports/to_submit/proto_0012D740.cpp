// bin: proto
// va: 0x0012D740
// what: Fills in the script system's description of the CarAITask class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x001AF2B0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CD30[];
extern "C" int DAT_00409388;
extern "C" int DAT_0040938C;
extern "C" char DAT_00409348[];
extern "C" char DAT_00409354[];
extern "C" char DAT_004095A8[];
extern "C" int DAT_004095CC;
extern "C" char sub_00129DF0[];
extern "C" void __cdecl sub_000660D0(int, int);
extern "C" void __cdecl sub_0002B000(int, int, int, int, int, int, int);

class CarAITask;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<CarAITask>::vfunc_02()
{
    sub_000660D0(DAT_004095CC, DAT_00409388);
    DAT_0040938C = (int)DAT_004095A8;
    sub_0002B000((int)DAT_00409348, (int)DAT_00409354, (int)DAT_0037CD30, (int)sub_00129DF0, 3, 3, (int)DAT_0037CD30);
}