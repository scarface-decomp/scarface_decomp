// bin: proto
// va: 0x000F5E20
// what: Looks a value up the first time, keeps it, and returns the kept value after that.
// tool: Claude Fable 5.2 (look-alike of proto 0x000F5EB0, names and addresses swapped)
// AITask_BasicInVehicle::vfunc_37 (0x000F5E20, 56 bytes)
extern "C" char DAT_0038AB84[];
extern "C" int DAT_0045BB58;
extern "C" bool DAT_0045BB5C;
extern "C" int __cdecl sub_00065CF0(int, int);

class AITask_BasicInVehicle
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
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual int vfunc_37();
};

int AITask_BasicInVehicle::vfunc_37()
{
    int t1;

    if (!(1 & DAT_0045BB5C)) {
        *(int*)&DAT_0045BB5C = *(int*)&DAT_0045BB5C | 1;
        t1 = sub_00065CF0((int)DAT_0038AB84, 0);
        DAT_0045BB58 = t1;
        return t1;
    }
    return DAT_0045BB58;
}
