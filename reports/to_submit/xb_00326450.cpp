// bin: xb
// va: 0x00326450
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326450 (0x00326450, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043A224;
extern "C" int DAT_0043A228;
extern "C" unsigned short DAT_0043A230;
extern "C" unsigned short DAT_0043A232;
extern "C" unsigned short DAT_0043A236;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326450(void)
{
    DAT_0043A224 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043A228);
    DAT_0043A228 = 0;
    DAT_0043A230 = 0;
    DAT_0043A232 = 0;
    DAT_0043A236 = 0;
    return 0;
}
