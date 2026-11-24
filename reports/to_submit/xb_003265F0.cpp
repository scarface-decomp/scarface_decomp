// bin: xb
// va: 0x003265F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003265F0 (0x003265F0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043ABA8;
extern "C" int DAT_0043ABAC;
extern "C" unsigned short DAT_0043ABB4;
extern "C" unsigned short DAT_0043ABB6;
extern "C" unsigned short DAT_0043ABBA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003265F0(void)
{
    DAT_0043ABA8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043ABAC);
    DAT_0043ABAC = 0;
    DAT_0043ABB4 = 0;
    DAT_0043ABB6 = 0;
    DAT_0043ABBA = 0;
    return 0;
}
