// bin: xb
// va: 0x00318B80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318B80 (0x00318B80, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004303BC[];
extern "C" char DAT_004303CC[];
extern "C" Object DAT_0048BAA0;
extern "C" char sub_001787D0[];

void __cdecl sub_00318B80(void)
{
    DAT_0048BAA0.sub_0006F830((int)DAT_004303CC, (int)DAT_004303BC, (int)sub_001787D0, 0, 3, 3);
}
