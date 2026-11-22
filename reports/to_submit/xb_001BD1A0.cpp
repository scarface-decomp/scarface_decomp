// bin: xb
// va: 0x001BD1A0
// what: Fills in the script system's description of the HUDElement2 class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x00024510, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00436684;
extern "C" int DAT_00436688;
extern "C" char DAT_00436690[];
extern "C" char DAT_00436698[];
extern "C" char DAT_0041BDC0[];
extern "C" int DAT_0041BDE0;
extern "C" void __cdecl sub_00070520(int, int);
extern "C" void __cdecl sub_00073780(int, int, int, int, int, int, int, int, int);

class HUDElement2;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<HUDElement2>::vfunc_02()
{
    sub_00070520(DAT_0041BDE0, DAT_00436684);
    DAT_00436688 = (int)DAT_0041BDC0;
    sub_00073780((int)DAT_00436698, 8, 0, 0, 84, 0, 0, 0, 0);
    sub_00073780((int)DAT_00436690, 8, 0, 0, 88, 0, 0, 0, 0);
}