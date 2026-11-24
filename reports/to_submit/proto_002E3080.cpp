// bin: proto
// va: 0x002E3080
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3080 (Proto 0x002E3080, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003FE31C[];
extern "C" char sub_002F1420[];
extern "C" void __cdecl sub_00068E40(int);
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E3080(void)
{
    sub_00068E40((int)DAT_003FE31C);
    sub_002C8EB3((int)sub_002F1420);
}
