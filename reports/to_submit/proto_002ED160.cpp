// bin: proto
// va: 0x002ED160
// what: Start-up code (a static initializer): stores the name key of "terminate" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ED160 (Proto 0x002ED160, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AC4BC[];
extern "C" int DAT_004635EC;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002ED160(void)
{
    DAT_004635EC = sub_00201440((int)DAT_003AC4BC, 0);
}
