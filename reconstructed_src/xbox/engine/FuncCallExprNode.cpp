// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/FuncCallExprNode.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] FuncCallExprNode::vfunc_03 (0x0006E600, 124 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FuncCallExprNode::vfunc_03 (Proto 0x00064330), which was matched first;
// its addresses and names were swapped for this function's.
// FuncCallExprNode::vfunc_03 (Proto 0x0006E600, 124 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int);
    void sub_0006E150(int, int, int);
};

extern "C" Object DAT_00479490;
extern "C" int __cdecl sub_000766D0(int);

class FuncCallExprNode
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int a1);
};

int FuncCallExprNode::vfunc_03(int a1)
{
    int r_edi, r_esi, t1, t4, t8;

    r_edi = 0;
    r_esi = (int)this;
    if (a1 != 3) {
        r_edi = 1;
    }
    t1 = *(int*)(r_esi + 16);
    if (*(int*)(r_esi + 16)) {
        DAT_00479490.sub_0006E150(sub_000766D0(t1), 1, 0);
    }
    t4 = *(int*)(r_esi + 20);
    if (*(int*)(r_esi + 20)) {
        DAT_00479490.sub_0006E150(sub_000766D0(t4), 1, 0);
    }
    r_esi = *(int*)(r_esi + 24);
    if (r_esi) {
        do {
            t8 = ((Object*)r_esi)->vfunc_03(3);
            r_esi = *(int*)(r_esi + 4);
            r_edi = r_edi + t8 + 1;
        } while (r_esi);
    }
    return r_edi + 7;
}

