// bin: proto
// va: 0x002E1150
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1150 (Proto 0x002E1150, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003F7390;
extern "C" float DAT_00449ED8;

void __cdecl sub_002E1150(void)
{
    float t1;

    t1 = DAT_003F7390;
    DAT_00449ED8 = t1 * t1;
}
