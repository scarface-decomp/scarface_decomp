// bin: proto
// va: 0x002E88F0
// what: Start-up code (a static initializer): stores the name key of "beamTurningOn" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E88F0 (Proto 0x002E88F0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039FC94[];
extern "C" int DAT_00460180;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002E88F0(void)
{
    DAT_00460180 = sub_00201440((int)DAT_0039FC94, 0);
}
