// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, om/ArrayFixed_char__4___16__.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::Garbage<container::ArrayFixed<container::ArrayFixed<char, 4>, 16>>::vfunc_00 (0x002A2480, 50 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// om::Garbage<container::ArrayFixed<container::ArrayFixed<char, 4>, 16>>::vfunc_00 (Proto 0x002A2480, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BA154[];
extern "C" char DAT_003BA15C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_002A24C0(int);

namespace om {

class Garbage_container__ArrayFixed_container__ArrayFixed_char__4___16__
{
public:
    virtual Garbage_container__ArrayFixed_container__ArrayFixed_char__4___16__* vfunc_00(bool a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

Garbage_container__ArrayFixed_container__ArrayFixed_char__4___16__* Garbage_container__ArrayFixed_container__ArrayFixed_char__4___16__::vfunc_00(bool a1)
{
    *(int*)this = (int)DAT_003BA15C;
    sub_00025160(m_Field08);
    *(int*)this = (int)DAT_003BA154;
    if (a1 & 1) {
        sub_002A24C0((int)this);
    }
    return this;
}

}

