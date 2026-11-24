// bin: xb
// va: 0x00317E50
// what: Start-up code (a static initializer): stores the name key of "inv_weight" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317E50 (0x00317E50, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B45D4[];
extern "C" int DAT_0048AA20;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00317E50(void)
{
    DAT_0048AA20 = sub_00244040((int)DAT_003B45D4, 0);
}
