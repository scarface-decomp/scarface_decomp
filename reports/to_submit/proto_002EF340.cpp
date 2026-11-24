// bin: proto
// va: 0x002EF340
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EF340 (Proto 0x002EF340, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002AE000();
};

extern "C" Object DAT_00490BC4;
extern "C" char sub_002F79A0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002EF340(void)
{
    DAT_00490BC4.sub_002AE000();
    sub_002C8EB3((int)sub_002F79A0);
}
