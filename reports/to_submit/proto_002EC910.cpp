// bin: proto
// va: 0x002EC910
// what: Start-up code (a static initializer): stores the name key of "ScriptCar" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC910 (Proto 0x002EC910, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A9B0C[];
extern "C" int DAT_00462EFC;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002EC910(void)
{
    DAT_00462EFC = sub_00201440((int)DAT_003A9B0C, 0);
}
