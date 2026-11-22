// bin: xb
// va: 0x0011C7F0
// what: Fills in the script system's description of the AITask_Engage class and lists its fields.
// tool: Claude Opus 5.5 (transplanted from proto:0x001AF2B0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D520[];
extern "C" int DAT_00428EEC;
extern "C" int DAT_00428EF0;
extern "C" char DAT_0042A7E4[];
extern "C" char DAT_0042A7F4[];
extern "C" char DAT_00428EA0[];
extern "C" int DAT_00428EC0;
extern "C" char sub_0010AA90[];
extern "C" void __cdecl sub_00070520(int, int);
extern "C" void __cdecl sub_0011BCB0(int, int, int, int, int, int, int);

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
    sub_00070520(DAT_00428EC0, DAT_00428EEC);
    DAT_00428EF0 = (int)DAT_00428EA0;
    sub_0011BCB0((int)DAT_0042A7E4, (int)DAT_0042A7F4, (int)DAT_0039D520, (int)sub_0010AA90, 3, 3, (int)DAT_0039D520);
}