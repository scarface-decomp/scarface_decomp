// bin: proto
// va: 0x0002BFE0
// tool: the portal's starter code (no AI)
// sub_0002BFE0 (0x0002BFE0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_003F6F98;
extern "C" bool DAT_004498BE;

int __cdecl sub_0002BFE0(void)
{
    if (!DAT_004498BE) {
        if (DAT_003F6F98) goto L_15;
        return 0;
    }
L_15:
    return 1;
}
