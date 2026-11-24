// bin: proto
// va: 0x002EBF20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EBF20 (Proto 0x002EBF20, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004620D4[];

int __cdecl sub_002EBF20(void)
{
    int r_eax, r_edx;

    r_eax = (int)DAT_004620D4;
    r_edx = 78;
    do {
        *(unsigned short*)(r_eax + -4) = 0;
        *(unsigned short*)(r_eax + -2) = 0;
        *(unsigned short*)r_eax = 0;
        *(unsigned short*)(r_eax + 2) = 0;
        *(unsigned short*)(r_eax + 4) = 0;
        r_eax += 12;
        r_edx -= 1;
    } while (r_edx);
    return r_eax;
}
