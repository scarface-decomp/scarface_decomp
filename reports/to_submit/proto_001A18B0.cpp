// bin: proto
// va: 0x001A18B0
// what: When a flag is set, sends the same message (64) to its two linked objects.
// tool: Claude Opus 5.5 (transplanted from xb:0x001D8FC0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldB0
{
    int sub_001A6530(int);
};

class CallForVehicleSpawnObject
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
    virtual void vfunc_37();
    char m_pad04[0xB0];
    FieldB0* m_FieldB4; // +0xB4
    FieldB0* m_FieldB8; // +0xB8
    bool m_FieldBC; // +0xBC
};

void CallForVehicleSpawnObject::vfunc_37()
{
    int r_eax;

    r_eax = m_FieldBC;
    if ((unsigned char)r_eax) {
        m_FieldB4->sub_001A6530(64);
        r_eax = m_FieldB8->sub_001A6530(64);
    }
}