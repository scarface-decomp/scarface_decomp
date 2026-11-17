// bin: proto
// va: 0x001A1D80
// tool: the portal's starter code (no AI)
// CallForVehicleSpawnObject::vfunc_36 (0x001A1D80, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldB4
{
    void sub_001A6530(int);
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
    virtual void vfunc_36(int a1, int a2, int a3, int a4);
    bool sub_001A19D0();
    char m_pad04[0x77];
    unsigned char m_Field7B; // +0x7B
    char m_pad7C[0x38];
    FieldB4* m_FieldB4; // +0xB4
    FieldB4* m_FieldB8; // +0xB8
    bool m_FieldBC; // +0xBC
};

void CallForVehicleSpawnObject::vfunc_36(int a1, int a2, int a3, int a4)
{
    int t5;

    if (m_Field7B & 1) {
        if (*(bool*)((int)m_FieldB4 + 20)) goto L_57;
        if (*(bool*)((int)m_FieldB8 + 20)) goto L_57;
        if (!sub_001A19D0()) goto L_57;
        m_FieldB4->sub_001A6530(64);
        m_FieldB8->sub_001A6530(64);
        t5 = m_Field7B & 254;
        m_FieldBC = false;
        m_Field7B = (unsigned char)t5;
    }
L_57:
    ;
}
