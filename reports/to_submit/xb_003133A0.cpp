// bin: xb
// va: 0x003133A0
// what: Start-up code (a static initializer): stores the name key of "MiamiRainyNightFillShape" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003133A0 (0x003133A0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A0740[];
extern "C" int DAT_004758E8;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_003133A0(void)
{
    DAT_004758E8 = sub_00244040((int)DAT_003A0740, 0);
}
