// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ContinueStmtNode.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ContinueStmtNode::vfunc_00 (0x00061BD0, 59 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as BreakStmtNode::vfunc_00 (0x0006BE00), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_00381A14[];
extern "C" unsigned char DAT_0044E084;
extern "C" int DAT_0044E080;
extern "C" void __cdecl sub_000656F0(int level, const char* message, int a3, int a4);

class ContinueStmtNode
{
public:
    virtual int vfunc_00(int a1);

    int m_04;
    int m_08;
    int m_0C;
};

// Script break statement: inside a loop it counts itself (when counting is on) and returns 2;
// outside one it reports an error (with two of the node's fields) and returns 0.
int ContinueStmtNode::vfunc_00(int a1)
{
    if (a1) {
        if (DAT_0044E084)
            DAT_0044E080++;
        return 2;
    }
    sub_000656F0(0, DAT_00381A14, m_08, m_0C);
    return 0;
}

