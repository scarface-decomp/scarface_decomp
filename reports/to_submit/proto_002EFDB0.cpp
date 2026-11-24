// bin: proto
// va: 0x002EFDB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EFDB0 (Proto 0x002EFDB0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00290E20(int, int);
};

extern "C" Object DAT_004910D4;
extern "C" int DAT_004910E0;
extern "C" int DAT_004910E4;
extern "C" char sub_002F7D40[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002EFDB0(void)
{
    DAT_004910D4.sub_00290E20(0, 0);
    DAT_004910E0 = 72;
    DAT_004910E4 = 8;
    sub_002C8EB3((int)sub_002F7D40);
}
