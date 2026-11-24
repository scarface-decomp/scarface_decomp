// bin: xb
// va: 0x0031EF10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031EF10 (0x0031EF10, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00490EF4[];

int __cdecl sub_0031EF10(void)
{
    int r_eax, r_edx;

    r_eax = (int)DAT_00490EF4;
    r_edx = 83;
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
