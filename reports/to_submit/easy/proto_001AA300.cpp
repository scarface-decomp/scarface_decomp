// bin: proto
// va: 0x001AA300
// tool: the portal's starter code (no AI)
// PersistentVehicleSpawnObject::vfunc_48 (0x001AA300, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1F4
{
    void sub_000AB750(int);
};

struct Object
{
    int sub_001DB950();
};

class PersistentVehicleSpawnObject
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
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual bool vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48(int a1, int a2);
    char m_pad04[0x1F0];
    Field1F4 m_Field1F4; // +0x1F4
    char m_pad1F5[0x7B];
    bool m_Field270; // +0x270
};

void PersistentVehicleSpawnObject::vfunc_48(int a1, int a2)
{
    int t1;

    if (!a2) goto L_46;
    if (a2 >= 5) goto L_46;
    if (!a1) goto L_46;
    t1 = ((Object*)a1)->sub_001DB950();
    if (t1) {
        if (!vfunc_41()) goto L_45;
        m_Field1F4.sub_000AB750(t1);
        m_Field270 = true;
    }
L_45:
L_46:
    ;
}
