// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/BreakStmtNode.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] BreakStmtNode::vfunc_00 (0x0006BE00, 59 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_003A24E8[];
extern "C" unsigned char DAT_004795A4;
extern "C" int DAT_004795A0;
extern "C" void __cdecl sub_002A9290(int level, const char* message, int a3, int a4);

class BreakStmtNode
{
public:
    virtual int vfunc_00(int a1);

    int m_04;
    int m_08;
    int m_0C;
};

// Script break statement: inside a loop it counts itself (when counting is on) and returns 2;
// outside one it reports an error (with two of the node's fields) and returns 0.
int BreakStmtNode::vfunc_00(int a1)
{
    if (a1) {
        if (DAT_004795A4)
            DAT_004795A0++;
        return 2;
    }
    sub_002A9290(0, DAT_003A24E8, m_08, m_0C);
    return 0;
}

