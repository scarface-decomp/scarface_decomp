// bin: xb
// va: 0x003191C0
// what: Start-up code (a static initializer): stores the name key of "NPCWeaponSpeed" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003191C0 (0x003191C0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B5D3C[];
extern "C" int DAT_0048BEE0;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_003191C0(void)
{
    DAT_0048BEE0 = sub_00244040((int)DAT_003B5D3C, 0);
}
