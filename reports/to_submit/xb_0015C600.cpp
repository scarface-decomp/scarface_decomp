// bin: xb
// va: 0x0015C600
// what: Fills in the script system's description of the CameraManager class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x00024510, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0042E7F4;
extern "C" int DAT_0042E7F8;
extern "C" char DAT_0042E800[];
extern "C" char DAT_0042E814[];
extern "C" char DAT_0041BDC0[];
extern "C" int DAT_0041BDE0;
extern "C" void __cdecl sub_00070520(int, int);
extern "C" void __cdecl sub_00073780(int, int, int, int, int, int, int, int, int);

class CameraManager;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<CameraManager>::vfunc_02()
{
    sub_00070520(DAT_0041BDE0, DAT_0042E7F4);
    DAT_0042E7F8 = (int)DAT_0041BDC0;
    sub_00073780((int)DAT_0042E814, 6, 0, 0, 244, 0, 0, 0, 0);
    sub_00073780((int)DAT_0042E800, 6, 0, 0, 248, 0, 0, 0, 0);
}