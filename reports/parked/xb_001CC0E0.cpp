// parked: 18/18 bytes, 1 address unchecked; same shape as 0x001C2520; stuck at the referent ?vfunc_45@PauseMenuPage@@ (0x001CA7F0, slot 45 of PauseMenuPage's vtable per RTTI, already matched as PauseMenuPage::vfunc_45) not being in reports/names.json. Needs names.json 'xb:0x001CA7F0' = PauseMenuPage::vfunc_45 (lane symcov-data).
// bin: xb
// va: 0x001CC0E0
// what: Passes the call on to the general pause-menu page's version and returns its yes/no answer.
// tool: Claude Opus 5.5 (symcov hint: TFXMeshInstance::SetTemplate, link-order)
// PauseMenuPageMain::vfunc_45 (0x001CC0E0, 18 bytes)
// RTTI: PauseMenuPageMain derives from PauseMenuPage, whose slot 45 is 0x001CA7F0, the function called here.
// Class shapes from reports/classes/xb/PauseMenuPage.h and PauseMenuPageMain.h.

class PauseMenuPage
{
public:
    virtual void* vfunc_00();
    virtual PauseMenuPage* vfunc_01(int a1);
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
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
    virtual void vfunc_35(int, int, int);
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual bool vfunc_45(int a1);
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    int sub_000CE360();
    char m_pad04[0x64];
    int m_Field68; // +0x68
    int m_Field6C; // +0x6C
    int m_Field70; // +0x70
    char m_pad74[0x4];
    bool m_Field78; // +0x78
};

class PauseMenuPageMain : public PauseMenuPage
{
public:
    virtual void* vfunc_00();
    virtual PauseMenuPageMain* vfunc_01(int a1);
    virtual bool vfunc_45(int a1);
};

// Defers to the base class.
bool PauseMenuPageMain::vfunc_45(int a1)
{
    if (PauseMenuPage::vfunc_45(a1))
    {
        return true;
    }
    return false;
}
