// bin: xb
// va: 0x00313480
// what: Start-up code (a static initializer): stores the name key of "LITE_MiamiFillShape" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313480 (0x00313480, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A0B78[];
extern "C" int DAT_0047592C;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00313480(void)
{
    DAT_0047592C = sub_00244040((int)DAT_003A0B78, 0);
}
