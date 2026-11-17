// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/PlayerHeadTracking.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PlayerHeadTracking::vfunc_08 (0x00160B40, 131 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PlayerHeadTracking::vfunc_08 (0x00160B40, 131 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00161030();
    void sub_001624E0();
    bool sub_00163300();
    int sub_00166CE0();
};

extern "C" int DAT_0048A9D8;
extern "C" int __cdecl sub_0015DDB0(void);

class PlayerHeadTracking
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
    virtual void vfunc_08(int a1);
    bool sub_00160010(int);
    bool sub_001600B0(int);
    bool sub_001605B0(int);
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    int m_Field34; // +0x34
};

void PlayerHeadTracking::vfunc_08(int a1)
{
    int r_ebx, r_edi;

    r_edi = DAT_0048A9D8;
    r_ebx = 0;
    if (!r_edi) goto L_7D;
    if (!((Object*)r_edi)->sub_00163300()) {
        m_Field30 = 0;
        m_Field34 = 0;
        return;
    }
    r_ebx = r_edi + 432;
    if (!((Object*)r_edi)->sub_00166CE0()) {
        if (sub_0015DDB0()) {
            if (((Object*)sub_0015DDB0())->sub_00161030()) goto L_76;
        }
        if (sub_00160010(r_ebx)) goto L_7D;
        if (sub_001605B0(r_ebx)) goto L_7D;
        if (sub_001600B0(r_ebx)) goto L_7D;
    }
L_76:
    ((Object*)r_ebx)->sub_001624E0();
L_7D:
    ;
}

