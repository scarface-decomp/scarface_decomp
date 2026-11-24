// bin: proto
// va: 0x002E5070
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5070 (Proto 0x002E5070, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0040410C[];
extern "C" char sub_002F2210[];
extern "C" void __cdecl sub_00068E40(int);
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E5070(void)
{
    sub_00068E40((int)DAT_0040410C);
    sub_002C8EB3((int)sub_002F2210);
}
