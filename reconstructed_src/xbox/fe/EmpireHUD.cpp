// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/EmpireHUD.cpp (3 verified)
// GENERATED from reports/verified_registry.json by tools/registry_outputs.py. Do not edit.
// Every block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] EmpireHUD::IsModalHUD (0x0006F990, 3 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/EmpireHUD.cpp
// ============================================================================
bool EmpireHUD::IsModalHUD() const {
    return true;
}

// ============================================================================
// [VERIFIED] EmpireHUD::~EmpireHUD (0x00192AB0, 30 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2 external relocation(s) unchecked | excerpt from reconstructed_src/EmpireHUD.cpp
// ============================================================================
* Slot [01] (+0x04): EmpireHUD::~EmpireHUD()
 *   PC v1.00.2 : 0x005C3800
 *   default.xbe: 0x00192AB0 (30B scalar deleting wrapper) + 0x00193F80 (22B body)
 */
EmpireHUD::~EmpireHUD() {
}

// ============================================================================
// [VERIFIED] EmpireHUD::GetClassRep (0x00194100, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/EmpireHUD.cpp
// ============================================================================
* Slot [00] (+0x00): EmpireHUD::GetClassRep()
 *   PC v1.00.2 : 0x005C37F0
 *   default.xbe: 0x00194100 (6 bytes: `B8 E4 66 43 00 C3`)
 */
AbstractClassRep* EmpireHUD::GetClassRep() const {
    return &sm_ConcreteClassRep;
}

