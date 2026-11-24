// bin: proto
// va: 0x002E88D0
// what: Start-up code (a static initializer): stores the name key of "beamOn" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E88D0 (Proto 0x002E88D0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039FC8C[];
extern "C" int DAT_0046017C;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002E88D0(void)
{
    DAT_0046017C = sub_00201440((int)DAT_0039FC8C, 0);
}
