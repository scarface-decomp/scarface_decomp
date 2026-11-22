// bin: proto
// va: 0x001018C0
// what: Fills in the script system's description of the AITask_Engage class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x001AF2B0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CD30[];
extern "C" int DAT_00403B2C;
extern "C" int DAT_00403B30;
extern "C" char DAT_0040548C[];
extern "C" char DAT_0040549C[];
extern "C" char DAT_00403ADC[];
extern "C" int DAT_00403B00;
extern "C" char sub_00242010[];
extern "C" void __cdecl sub_000660D0(int, int);
extern "C" void __cdecl sub_0011C0F0(int, int, int, int, int, int, int);

class AITask_Engage;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<AITask_Engage>::vfunc_02()
{
    sub_000660D0(DAT_00403B00, DAT_00403B2C);
    DAT_00403B30 = (int)DAT_00403ADC;
    sub_0011C0F0((int)DAT_0040548C, (int)DAT_0040549C, (int)DAT_0037CD30, (int)sub_00242010, 3, 3, (int)DAT_0037CD30);
}