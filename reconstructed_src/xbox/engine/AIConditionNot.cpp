// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AIConditionNot.cpp (1 verified)
// GENERATED from reports/verified_registry.json by tools/registry_outputs.py. Do not edit.
// Every block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIConditionNot::Evaluate (0x00121990, 14 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/StarterBatch1_25Functions.cpp
// ============================================================================
bool SCARFACE_X86_THISCALL AIConditionNot::Evaluate() {
    return !m_pChildCondition08->Evaluate();
}

