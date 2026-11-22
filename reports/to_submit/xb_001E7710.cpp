// bin: xb
// va: 0x001E7710
// what: Fills in the script system's description of the AmbientSpawnObject class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from xb:0x000268A0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0043DA68;
extern "C" int DAT_0043DA6C;
extern "C" char DAT_0043CD94[];
extern "C" char DAT_0043CDA4[];
extern "C" char DAT_0043D8E8[];
extern "C" int DAT_0043D908;
extern "C" void __cdecl sub_00070520(int, int);
extern "C" void __cdecl sub_00073780(int, int, int, int, int, int, int, int, int);

class AmbientSpawnObject;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<AmbientSpawnObject>::vfunc_02()
{
    sub_00070520(DAT_0043D908, DAT_0043DA68);
    DAT_0043DA6C = (int)DAT_0043D8E8;
    sub_00073780((int)DAT_0043CDA4, 2, 0, 0, 248, 0, 0, 0, 0);
    sub_00073780((int)DAT_0043CD94, 2, 0, 0, 236, 0, 0, 0, 0);
}