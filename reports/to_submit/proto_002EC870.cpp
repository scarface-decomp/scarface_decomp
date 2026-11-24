// bin: proto
// va: 0x002EC870
// what: Start-up code (a static initializer): stores the name key of "DWHenchman" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC870 (Proto 0x002EC870, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00393898[];
extern "C" int DAT_00462EE8;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002EC870(void)
{
    DAT_00462EE8 = sub_00201440((int)DAT_00393898, 0);
}
