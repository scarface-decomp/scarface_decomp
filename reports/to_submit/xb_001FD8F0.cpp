// bin: xb
// va: 0x001FD8F0
// what: Fills in the script system's description of the SkyTemplate class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x00024510, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004402F0;
extern "C" int DAT_004402F4;
extern "C" char DAT_00440284[];
extern "C" char DAT_00440290[];
extern "C" char DAT_0041C010[];
extern "C" int DAT_0041C030;
extern "C" void __cdecl sub_00070520(int, int);
extern "C" void __cdecl sub_00073780(int, int, int, int, int, int, int, int, int);

class SkyTemplate;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<SkyTemplate>::vfunc_02()
{
    sub_00070520(DAT_0041C030, DAT_004402F0);
    DAT_004402F4 = (int)DAT_0041C010;
    sub_00073780((int)DAT_00440290, 8, 0, 0, 36, 0, 0, 0, 0);
    sub_00073780((int)DAT_00440284, 8, 0, 0, 40, 0, 0, 0, 0);
}