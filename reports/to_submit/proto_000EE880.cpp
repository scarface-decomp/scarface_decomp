// bin: proto
// va: 0x000EE880
// what: Calls a function with this object, 1 and a fixed block of the game's data.
// tool: Claude Fable 5.2 (look-alike of proto 0x000EE8A0, names and addresses swapped)
// AITask::vfunc_28 (0x000EE880, 17 bytes)
extern "C" char DAT_003898BC[];
extern "C" void __cdecl sub_00066030(int, int, int);

class AITask
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
};

void AITask::vfunc_28()
{
    sub_00066030((int)this, 1, (int)DAT_003898BC);
}
