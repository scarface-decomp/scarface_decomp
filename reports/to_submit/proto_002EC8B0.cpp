// bin: proto
// va: 0x002EC8B0
// what: Start-up code (a static initializer): stores the name key of "DWStreetDealer" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC8B0 (Proto 0x002EC8B0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003938B0[];
extern "C" int DAT_00462EF0;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002EC8B0(void)
{
    DAT_00462EF0 = sub_00201440((int)DAT_003938B0, 0);
}
