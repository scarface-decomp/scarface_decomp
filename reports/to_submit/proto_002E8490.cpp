// bin: proto
// va: 0x002E8490
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8490 (Proto 0x002E8490, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00411D54[];
extern "C" char sub_002F42A0[];
extern "C" void __cdecl sub_00068E40(int);
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E8490(void)
{
    sub_00068E40((int)DAT_00411D54);
    sub_002C8EB3((int)sub_002F42A0);
}
