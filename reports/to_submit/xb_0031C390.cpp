// bin: xb
// va: 0x0031C390
// what: Start-up code (a static initializer): stores the name key of "On_Mission_Fail" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031C390 (0x0031C390, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C865C[];
extern "C" int DAT_0048F6D8;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031C390(void)
{
    DAT_0048F6D8 = sub_00244040((int)DAT_003C865C, 0);
}
