// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AITask_IdleChatResponse.cpp (2 verified)
// GENERATED from reports/verified_registry.json by tools/registry_outputs.py. Do not edit.
// Every block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_IdleChatResponse::vfunc_00 (0x0011C920, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_0042923C; void* __cdecl sub_0011C920(void) { return &DAT_0042923C; }

// ============================================================================
// [VERIFIED] AITask_IdleChatResponse::vfunc_49 (0x001262C0, 14 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2 external relocation(s) unchecked | excerpt from reconstructed_src/StarterBatch1_25Functions.cpp
// ============================================================================
void SCARFACE_X86_THISCALL AITask_IdleChatResponse::vfunc_49() {
    ++Batch1Externals::g_IdleChatResponseCount;
    m_SubComp60.ActivateSubTask();
}

