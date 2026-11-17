// bin: xb
// va: 0x0002EAA0
// tool: the portal's starter code (no AI)
// sub_0002EAA0 (0x0002EAA0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0041C040;
extern "C" bool DAT_00474517;

int __cdecl sub_0002EAA0(void)
{
    if (!DAT_00474517) {
        if (DAT_0041C040) goto L_15;
        return 0;
    }
L_15:
    return 1;
}
