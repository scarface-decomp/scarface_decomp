// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/pddiLightingState_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::pddiStack<pure3d::pddiLightingState>::vfunc_00 (0x00262E50, 44 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::pddiStack<pure3d::pddiLightingState>::vfunc_00 (Proto 0x00262E50, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B3708[];
extern "C" void __cdecl sub_00025160(int);

namespace pure3d { class pddiLightingState; }

namespace pure3d { 
template <class T0> class pddiStack
{
public:
    virtual pddiStack<pure3d::pddiLightingState>* vfunc_00(bool a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};
}

template <> pure3d::pddiStack<pure3d::pddiLightingState>* pure3d::pddiStack<pure3d::pddiLightingState>::vfunc_00(bool a1)
{
    *(int*)this = (int)DAT_003B3708;
    sub_00025160(m_Field0C);
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

