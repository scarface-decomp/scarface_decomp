// bin: xb
// va: 0x0031F580
// what: Start-up code (a static initializer): stores the name key of "EHE_DISTANCE_BUBBLE2" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F580 (0x0031F580, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BB77C[];
extern "C" int DAT_00491E04;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031F580(void)
{
    DAT_00491E04 = sub_00244040((int)DAT_003BB77C, 0);
}
