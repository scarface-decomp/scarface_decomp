// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/StreamManagerFlowClient.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] StreamManagerFlowClient::vfunc_00 (0x00085550, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// StreamManagerFlowClient::vfunc_00 (0x00085550, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00383884[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_000D7D00(void);

class StreamManagerFlowClient
{
public:
    virtual void vfunc_00();
    virtual StreamManagerFlowClient* vfunc_00(int a1);
};

StreamManagerFlowClient* StreamManagerFlowClient::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00383884;
    sub_000D7D00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] StreamManagerFlowClient::vfunc_01 (0x000862D0, 77 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// StreamManagerFlowClient::vfunc_01 (Proto 0x000862D0, 77 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00084EB0();
};

extern "C" int DAT_00453F04;
extern "C" void __cdecl sub_000858A0(void);
extern "C" void __cdecl sub_00085980(void);
extern "C" void __cdecl sub_00085BC0(int);

class StreamManagerFlowClient
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1, int a2);
    int m_Field04; // +0x04
};

int StreamManagerFlowClient::vfunc_01(int a1, int a2)
{
    int r_edi, r_esi;

    m_Field04 = 0;
    sub_000858A0();
    if (a2 != 32) {
        sub_00085980();
    }
    r_esi = *(int*)DAT_00453F04;
    r_edi = *(int*)(DAT_00453F04 + 4);
    if (r_esi != r_edi) {
        do {
            ((Object*)*(int*)r_esi)->sub_00084EB0();
            r_esi += 4;
        } while (r_esi != r_edi);
    }
    sub_00085BC0(a1);
    return 4;
}

// ============================================================================
// [VERIFIED] StreamManagerFlowClient::vfunc_02 (0x00086320, 65 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// StreamManagerFlowClient::vfunc_02 (Proto 0x00086320, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00084EB0();
};

extern "C" int DAT_00453F04;
extern "C" void __cdecl sub_000858A0(void);
extern "C" void __cdecl sub_00085980(void);
extern "C" void __cdecl sub_00085BC0(int);

class StreamManagerFlowClient
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, int a2, int a3);
};

void StreamManagerFlowClient::vfunc_02(int a1, int a2, int a3)
{
    int r_edi, r_esi;

    sub_000858A0();
    if (a2 != 32) {
        sub_00085980();
    }
    r_esi = *(int*)DAT_00453F04;
    r_edi = *(int*)(DAT_00453F04 + 4);
    if (r_esi != r_edi) {
        do {
            ((Object*)*(int*)r_esi)->sub_00084EB0();
            r_esi += 4;
        } while (r_esi != r_edi);
    }
    sub_00085BC0(a1);
}

