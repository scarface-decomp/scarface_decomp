// bin: xb
// va: 0x00317D70
// what: Start-up code (a static initializer): stores the name key of "Stamina" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317D70 (0x00317D70, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B3AE4[];
extern "C" int DAT_0048A954;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00317D70(void)
{
    DAT_0048A954 = sub_00244040((int)DAT_003B3AE4, 0);
}
