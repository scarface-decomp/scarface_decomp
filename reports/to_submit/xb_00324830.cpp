// bin: xb
// va: 0x00324830
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324830 (0x00324830, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0048A19C;
extern "C" int DAT_0048A1A0;
extern "C" int DAT_0048A1AC;
extern "C" int DAT_0048A1B0;
extern "C" int DAT_0048A1BC;
extern "C" int DAT_0048A1C0;
extern "C" void __cdecl sub_00027600(int);

void __cdecl sub_00324830(void)
{
    int t1, t3, t5;

    t1 = DAT_0048A1BC;
    DAT_0048A1C0 = DAT_0048A1BC;
    if (DAT_0048A1BC) {
        sub_00027600(t1);
    }
    t3 = DAT_0048A1AC;
    DAT_0048A1B0 = DAT_0048A1AC;
    if (DAT_0048A1AC) {
        sub_00027600(t3);
    }
    t5 = DAT_0048A19C;
    DAT_0048A1A0 = DAT_0048A19C;
    if (DAT_0048A19C) {
        sub_00027600(t5);
    }
}
