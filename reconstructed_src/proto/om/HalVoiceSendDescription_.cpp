// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, om/HalVoiceSendDescription_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::Garbage<audio::HalVoiceSendDescription>::vfunc_00 (0x002A3420, 50 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// om::Garbage<audio::HalVoiceSendDescription>::vfunc_00 (Proto 0x002A3420, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BA154[];
extern "C" char DAT_003BA2A8[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_002A3460(int);

namespace audio { class HalVoiceSendDescription; }

namespace om { 
template <class T0> class Garbage
{
public:
    virtual Garbage<audio::HalVoiceSendDescription>* vfunc_00(bool a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};
}

template <> om::Garbage<audio::HalVoiceSendDescription>* om::Garbage<audio::HalVoiceSendDescription>::vfunc_00(bool a1)
{
    *(int*)this = (int)DAT_003BA2A8;
    sub_00025160(m_Field08);
    *(int*)this = (int)DAT_003BA154;
    if (a1 & 1) {
        sub_002A3460((int)this);
    }
    return this;
}

