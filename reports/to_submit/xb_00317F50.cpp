// bin: xb
// va: 0x00317F50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317F50 (0x00317F50, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0042F578;
extern "C" int DAT_0048AA9C;

int __cdecl sub_00317F50(void)
{
    int t1;

    t1 = DAT_0042F578;
    DAT_0048AA9C = DAT_0042F578;
    return t1;
}
