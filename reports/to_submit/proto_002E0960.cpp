// bin: proto
// va: 0x002E0960
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0960 (Proto 0x002E0960, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037E924[];
extern "C" char DAT_00446FB8[];
extern "C" char sub_002F0DD0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E0960(void)
{
    int r_eax, r_ecx;

    r_eax = (int)DAT_00446FB8;
    r_ecx = 22;
    do {
        *(int*)r_eax = (int)DAT_0037E924;
        r_eax += 72;
        r_ecx -= 1;
    } while (r_ecx);
    sub_002C8EB3((int)sub_002F0DD0);
}
