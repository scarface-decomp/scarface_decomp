// bin: xb
// va: 0x003127D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003127D0 (0x003127D0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039F2B4[];
extern "C" char DAT_00472290[];
extern "C" char sub_00322970[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_003127D0(void)
{
    int r_eax, r_ecx;

    r_eax = (int)DAT_00472290;
    r_ecx = 103;
    do {
        *(int*)r_eax = (int)DAT_0039F2B4;
        r_eax += 72;
        r_ecx -= 1;
    } while (r_ecx);
    sub_002FBBEF((int)sub_00322970);
}
