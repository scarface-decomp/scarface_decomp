// bin: xb
// va: 0x00313890
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313890 (0x00313890, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB410(int, int, int);
};

extern "C" Object DAT_00476419;
extern "C" char sub_000670D0[];

void __cdecl sub_00313890(void)
{
    DAT_00476419.sub_000EB410(44, (int)sub_000670D0, 0);
}
