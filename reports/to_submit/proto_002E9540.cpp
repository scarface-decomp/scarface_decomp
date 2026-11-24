// bin: proto
// va: 0x002E9540
// what: Start-up code (a static initializer): stores the name key of "CubeVan" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9540 (Proto 0x002E9540, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A173C[];
extern "C" int DAT_00460AB0;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002E9540(void)
{
    DAT_00460AB0 = sub_00201440((int)DAT_003A173C, 0);
}
