// bin: xb
// va: 0x00318B20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318B20 (0x00318B20, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_00430350[];
extern "C" char DAT_00430368[];
extern "C" Object DAT_0048BA1C;
extern "C" char sub_00178760[];

void __cdecl sub_00318B20(void)
{
    DAT_0048BA1C.sub_0006F790((int)DAT_00430368, (int)DAT_00430350, (int)sub_00178760, 0, 2, 2);
}
