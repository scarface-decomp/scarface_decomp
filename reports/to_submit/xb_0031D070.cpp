// bin: xb
// va: 0x0031D070
// what: Start-up code (a static initializer): stores the name key of "TargetingHUDUpdater" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031D070 (0x0031D070, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CA738[];
extern "C" int DAT_004902C0;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031D070(void)
{
    DAT_004902C0 = sub_00244040((int)DAT_003CA738, 0);
}
