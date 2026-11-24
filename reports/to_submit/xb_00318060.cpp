// bin: xb
// va: 0x00318060
// what: Start-up code (a static initializer): stores the name key of "INV_OBJ_" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318060 (0x00318060, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B45F0[];
extern "C" int DAT_0048ADC0;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00318060(void)
{
    DAT_0048ADC0 = sub_00244040((int)DAT_003B45F0, 0);
}
