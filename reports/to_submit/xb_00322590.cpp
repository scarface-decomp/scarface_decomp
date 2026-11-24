// bin: xb
// va: 0x00322590
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322590 (0x00322590, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0046C030;
extern "C" int DAT_0046C034;
extern "C" void __cdecl sub_00027600(int);

void __cdecl sub_00322590(void)
{
    int t1;

    t1 = DAT_0046C030;
    DAT_0046C034 = DAT_0046C030;
    if (DAT_0046C030) {
        sub_00027600(t1);
    }
}
