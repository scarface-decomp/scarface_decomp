// bin: proto
// va: 0x002EC850
// what: Start-up code (a static initializer): stores the name key of "DeadBody" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC850 (Proto 0x002EC850, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039387C[];
extern "C" int DAT_00462EE4;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002EC850(void)
{
    DAT_00462EE4 = sub_00201440((int)DAT_0039387C, 0);
}
