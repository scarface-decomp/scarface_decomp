// bin: proto
// va: 0x002E7050
// what: Start-up code (a static initializer): stores the name key of "car_purchased" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7050 (Proto 0x002E7050, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00396EE4[];
extern "C" int DAT_0045E034;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002E7050(void)
{
    DAT_0045E034 = sub_00201440((int)DAT_00396EE4, 0);
}
