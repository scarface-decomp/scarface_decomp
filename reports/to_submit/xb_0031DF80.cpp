// bin: xb
// va: 0x0031DF80
// what: Start-up code (a static initializer): stores the name key of "DefaultRandomWaterObjectTemplate" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031DF80 (0x0031DF80, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CFD08[];
extern "C" int DAT_00490588;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031DF80(void)
{
    DAT_00490588 = sub_00244040((int)DAT_003CFD08, 0);
}
