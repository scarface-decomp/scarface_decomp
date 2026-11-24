// bin: xb
// va: 0x00323890
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323890 (0x00323890, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00429134;
extern "C" int DAT_00429138;
extern "C" unsigned short DAT_00429140;
extern "C" unsigned short DAT_00429142;
extern "C" unsigned short DAT_00429146;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323890(void)
{
    DAT_00429134 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00429138);
    DAT_00429138 = 0;
    DAT_00429140 = 0;
    DAT_00429142 = 0;
    DAT_00429146 = 0;
    return 0;
}
