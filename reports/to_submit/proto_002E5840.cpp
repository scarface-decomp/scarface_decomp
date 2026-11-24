// bin: proto
// va: 0x002E5840
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5840 (Proto 0x002E5840, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00409ADC[];
extern "C" char DAT_00409AF8[];
extern "C" Object DAT_0045C5E8;
extern "C" char sub_00141A10[];

void __cdecl sub_002E5840(void)
{
    DAT_0045C5E8.sub_00065550((int)DAT_00409AF8, (int)DAT_00409ADC, (int)sub_00141A10, 0, 3, 3);
}
