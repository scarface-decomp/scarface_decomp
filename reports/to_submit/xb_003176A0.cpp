// bin: xb
// va: 0x003176A0
// what: Start-up code (a static initializer): stores the name key of "red" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003176A0 (0x003176A0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B2CA0[];
extern "C" int DAT_0048A164;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_003176A0(void)
{
    DAT_0048A164 = sub_00244040((int)DAT_003B2CA0, 0);
}
