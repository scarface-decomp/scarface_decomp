// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/FunctionDeclStmtNode.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 3 functions matched (33.33%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] FunctionDeclStmtNode::vfunc_02 (0x000D0C00, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FunctionDeclStmtNode::vfunc_02 (0x0006BD80), which was matched first;
// its addresses and names were swapped for this function's.
// FunctionDeclStmtNode::vfunc_02 (0x000D0C00, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class FunctionDeclStmtNode
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02(int a1);
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

int FunctionDeclStmtNode::vfunc_02(int a1)
{
    m_Field20 = a1;
    return a1;
}

