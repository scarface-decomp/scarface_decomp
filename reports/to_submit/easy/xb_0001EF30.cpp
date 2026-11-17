// bin: xb
// va: 0x0001EF30
// tool: the portal's starter code (no AI)
// sub_0001EF30 (0x0001EF30, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D580;
extern "C" float DAT_00471504;
extern "C" bool DAT_00471512;

float __cdecl sub_0001EF30(bool a1)
{
    int r_eax;

    r_eax = 0;
    if (DAT_00471504 > DAT_0039D580) {
        r_eax = a1;
        if (!a1) goto L_26;
        DAT_00471512 = true;
    }
L_26:
    return DAT_00471504;
}
