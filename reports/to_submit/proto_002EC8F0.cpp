// bin: proto
// va: 0x002EC8F0
// what: Start-up code (a static initializer): stores the name key of "CubeVan" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC8F0 (Proto 0x002EC8F0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A173C[];
extern "C" int DAT_00462EF8;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002EC8F0(void)
{
    DAT_00462EF8 = sub_00201440((int)DAT_003A173C, 0);
}
