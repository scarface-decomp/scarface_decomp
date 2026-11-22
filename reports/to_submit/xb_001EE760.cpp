// bin: xb
// va: 0x001EE760
// what: Fills in the script system's description of the StatePropDragTemplate class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x00024510, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0043E760;
extern "C" int DAT_0043E764;
extern "C" char DAT_0043E618[];
extern "C" char DAT_0043E62C[];
extern "C" char DAT_0043E150[];
extern "C" int DAT_0043E170;
extern "C" void __cdecl sub_00070520(int, int);
extern "C" void __cdecl sub_00073780(int, int, int, int, int, int, int, int, int);

class StatePropDragTemplate;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<StatePropDragTemplate>::vfunc_02()
{
    sub_00070520(DAT_0043E170, DAT_0043E760);
    DAT_0043E764 = (int)DAT_0043E150;
    sub_00073780((int)DAT_0043E62C, 6, 0, 0, 36, 0, 0, 0, 0);
    sub_00073780((int)DAT_0043E618, 6, 0, 0, 40, 0, 0, 0, 0);
}