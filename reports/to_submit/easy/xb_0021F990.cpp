// bin: xb
// va: 0x0021F990
// tool: the portal's starter code (no AI)
// sub_0021F990 (0x0021F990, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003D0E64;
extern "C" float DAT_004914A4;

int __cdecl sub_0021F990(void)
{
    if (DAT_004914A4 >= DAT_003D0E64) {
        return 1;
    }
    return 0;
}
