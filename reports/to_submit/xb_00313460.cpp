// bin: xb
// va: 0x00313460
// what: Start-up code (a static initializer): stores the name key of "LITE_MiamiAmbientShape" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313460 (0x00313460, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A0B60[];
extern "C" int DAT_00475928;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00313460(void)
{
    DAT_00475928 = sub_00244040((int)DAT_003A0B60, 0);
}
