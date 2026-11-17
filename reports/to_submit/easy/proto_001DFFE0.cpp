// bin: proto
// va: 0x001DFFE0
// tool: the portal's starter code (no AI)
// CubeVan::vfunc_48 (0x001DFFE0, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldF8
{
    void sub_0008D4C0(int);
};

extern "C" char DAT_003F45D8[];
extern "C" char DAT_003F47F4[];
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

class CubeVan
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
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48(int a1, bool a2);
    char m_pad04[0xF4];
    FieldF8 m_FieldF8; // +0xF8
    char m_padF9[0x7];
    bool m_Field100; // +0x100
};

void CubeVan::vfunc_48(int a1, bool a2)
{
    if (!m_Field100) {
        if (!a2) goto L_43;
        m_FieldF8.sub_0008D4C0(sub_002C92F8(a1, 0, (int)DAT_003F45D8, (int)DAT_003F47F4, 0));
        m_Field100 = true;
    }
L_43:
    ;
}
