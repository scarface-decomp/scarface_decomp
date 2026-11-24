// bin: xb
// va: 0x00318F60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318F60 (0x00318F60, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_004313A8[];
extern "C" char DAT_004313BC[];
extern "C" Object DAT_0048BD08;
extern "C" char sub_0017A760[];

void __cdecl sub_00318F60(void)
{
    DAT_0048BD08.sub_0006F790((int)DAT_004313BC, (int)DAT_004313A8, (int)sub_0017A760, 0, 3, 3);
}
