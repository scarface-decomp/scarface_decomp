// bin: xb
// va: 0x0031FB60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FB60 (0x0031FB60, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00491FF0;
extern "C" bool __cdecl sub_0006F990(void);

int __cdecl sub_0031FB60(void)
{
    bool t1;

    t1 = sub_0006F990();
    DAT_00491FF0 = (unsigned char)t1;
    return (unsigned char)t1;
}
