// bin: xb
// va: 0x00313500
// what: Start-up code (a static initializer): stores the name key of "zone_rainlights" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313500 (0x00313500, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A0B98[];
extern "C" int DAT_0047593C;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00313500(void)
{
    DAT_0047593C = sub_00244040((int)DAT_003A0B98, 0);
}
