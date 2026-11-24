// bin: xb
// va: 0x0031CE50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031CE50 (0x0031CE50, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0043ED94;
extern "C" int DAT_004901D8;
extern "C" int __cdecl sub_00244040(int, int);

int __cdecl sub_0031CE50(void)
{
    int r_eax;

    r_eax = DAT_0043ED94;
    if (r_eax) {
        if (!*(unsigned char*)r_eax) goto L_1E;
        r_eax = sub_00244040(r_eax, 0);
        DAT_004901D8 = r_eax;
    }
L_1E:
    return r_eax;
}
