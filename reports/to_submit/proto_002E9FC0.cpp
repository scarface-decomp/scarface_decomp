// bin: proto
// va: 0x002E9FC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9FC0 (Proto 0x002E9FC0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00418510;
extern "C" int DAT_00461550;
extern "C" int __cdecl sub_002014E0(int, int);

int __cdecl sub_002E9FC0(void)
{
    int r_eax;

    r_eax = DAT_00418510;
    if (r_eax) {
        if (!*(unsigned char*)r_eax) goto L_1E;
        r_eax = sub_002014E0(r_eax, 0);
        DAT_00461550 = r_eax;
    }
L_1E:
    return r_eax;
}
