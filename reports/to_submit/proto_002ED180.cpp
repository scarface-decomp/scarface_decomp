// bin: proto
// va: 0x002ED180
// what: Start-up code (a static initializer): stores the name key of "enable_keys" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ED180 (Proto 0x002ED180, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AC4C8[];
extern "C" int DAT_004635F0;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002ED180(void)
{
    DAT_004635F0 = sub_00201440((int)DAT_003AC4C8, 0);
}
