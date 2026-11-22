// bin: proto
// va: 0x00101910
// what: Fills in the script system's description of the AITask_WaitWhenTonyIsNear class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x001AF2B0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CD30[];
extern "C" int DAT_00403CE4;
extern "C" int DAT_00403CE8;
extern "C" char DAT_004054D8[];
extern "C" char DAT_004054F4[];
extern "C" char DAT_00403ADC[];
extern "C" int DAT_00403B00;
extern "C" char sub_000F77E0[];
extern "C" void __cdecl sub_000660D0(int, int);
extern "C" void __cdecl sub_0011C0F0(int, int, int, int, int, int, int);

class AITask_WaitWhenTonyIsNear;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<AITask_WaitWhenTonyIsNear>::vfunc_02()
{
    sub_000660D0(DAT_00403B00, DAT_00403CE4);
    DAT_00403CE8 = (int)DAT_00403ADC;
    sub_0011C0F0((int)DAT_004054D8, (int)DAT_004054F4, (int)DAT_0037CD30, (int)sub_000F77E0, 3, 3, (int)DAT_0037CD30);
}