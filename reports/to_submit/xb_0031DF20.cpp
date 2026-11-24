// bin: xb
// va: 0x0031DF20
// what: Start-up code (a static initializer): stores the name key of "GlobalSkidmarkTemplate" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031DF20 (0x0031DF20, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CFB30[];
extern "C" int DAT_0049056C;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031DF20(void)
{
    DAT_0049056C = sub_00244040((int)DAT_003CFB30, 0);
}
