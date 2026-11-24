// bin: proto
// va: 0x002ED1E0
// what: Start-up code (a static initializer): stores the name key of "set_callback" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ED1E0 (Proto 0x002ED1E0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AC4E8[];
extern "C" int DAT_004635FC;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002ED1E0(void)
{
    DAT_004635FC = sub_00201440((int)DAT_003AC4E8, 0);
}
