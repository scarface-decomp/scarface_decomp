// bin: xb
// va: 0x003191A0
// what: Start-up code (a static initializer): stores the name key of "MidgetSpeedTemplate" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003191A0 (0x003191A0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B5D28[];
extern "C" int DAT_0048BED8;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_003191A0(void)
{
    DAT_0048BED8 = sub_00244040((int)DAT_003B5D28, 0);
}
