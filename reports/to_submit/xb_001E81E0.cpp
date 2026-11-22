// bin: xb
// va: 0x001E81E0
// what: Fills in the script system's description of the DealerSpawnObject class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x001AF2B0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D520[];
extern "C" int DAT_0043DB9C;
extern "C" int DAT_0043DBA0;
extern "C" char DAT_0043D840[];
extern "C" char DAT_0043D854[];
extern "C" char DAT_0043D864[];
extern "C" int DAT_0043D884;
extern "C" char sub_001DEC10[];
extern "C" void __cdecl sub_00070520(int, int);
extern "C" void __cdecl sub_001368B0(int, int, int, int, int, int, int);

class DealerSpawnObject;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<DealerSpawnObject>::vfunc_02()
{
    sub_00070520(DAT_0043D884, DAT_0043DB9C);
    DAT_0043DBA0 = (int)DAT_0043D864;
    sub_001368B0((int)DAT_0043D840, (int)DAT_0043D854, (int)DAT_0039D520, (int)sub_001DEC10, 3, 3, (int)DAT_0039D520);
}