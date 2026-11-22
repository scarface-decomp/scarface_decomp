// bin: xb
// va: 0x001D7980
// what: Fills in the script system's description of the ZoneSoundObject class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x00024510, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0043BC8C;
extern "C" int DAT_0043BC90;
extern "C" char DAT_0043BC14[];
extern "C" char DAT_0043BC24[];
extern "C" char DAT_0041BDC0[];
extern "C" int DAT_0041BDE0;
extern "C" void __cdecl sub_00070520(int, int);
extern "C" void __cdecl sub_00073780(int, int, int, int, int, int, int, int, int);

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
    sub_00070520(DAT_0041BDE0, DAT_0043BC8C);
    DAT_0043BC90 = (int)DAT_0041BDC0;
    sub_00073780((int)DAT_0043BC24, 8, 0, 0, 32, 0, 0, 0, 0);
    sub_00073780((int)DAT_0043BC14, 8, 0, 0, 36, 0, 0, 0, 0);
}