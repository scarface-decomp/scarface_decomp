// bin: proto
// va: 0x002EB9B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB9B0 (Proto 0x002EB9B0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00462058[];

int __cdecl sub_002EB9B0(void)
{
    int r_eax, r_ecx, r_edx;

    r_edx = 0;
    r_eax = (int)DAT_00462058;
    r_ecx = 15;
    r_edx |= -1;
    do {
        *(unsigned short*)r_eax = 0;
        *(int*)(r_eax + 4) = r_edx;
        r_eax += 8;
        r_ecx -= 1;
    } while (r_ecx);
    return r_eax;
}
