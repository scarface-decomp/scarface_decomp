// bin: xb
// va: 0x00322570
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322570 (0x00322570, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0046C020;
extern "C" int DAT_0046C024;
extern "C" void __cdecl sub_00027600(int);

void __cdecl sub_00322570(void)
{
    int t1;

    t1 = DAT_0046C020;
    DAT_0046C024 = DAT_0046C020;
    if (DAT_0046C020) {
        sub_00027600(t1);
    }
}
