// bin: xb
// va: 0x0031C350
// what: Start-up code (a static initializer): stores the name key of "On_Spawner_Delete" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031C350 (0x0031C350, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C8634[];
extern "C" int DAT_0048F6D0;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031C350(void)
{
    DAT_0048F6D0 = sub_00244040((int)DAT_003C8634, 0);
}
