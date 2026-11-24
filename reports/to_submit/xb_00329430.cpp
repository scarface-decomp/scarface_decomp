// bin: xb
// va: 0x00329430
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00329430 (0x00329430, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004C061C;
extern "C" int DAT_004C0620;
extern "C" int DAT_004C0628;
extern "C" int DAT_004C0644;
extern "C" int __cdecl sub_00027600(int);
extern "C" void __cdecl sub_002EFD10(int, int);

int __cdecl sub_00329430(void)
{
    int r_eax;

    r_eax = DAT_004C0644;
    if (r_eax) {
        sub_00027600(r_eax);
    }
    r_eax = DAT_004C0628;
    if (r_eax) {
        sub_00027600(r_eax);
    }
    r_eax = DAT_004C061C;
    if (r_eax) {
        sub_002EFD10(r_eax, DAT_004C0620);
        r_eax = sub_00027600(DAT_004C061C);
    }
    return r_eax;
}
