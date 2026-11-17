// bin: proto
// va: 0x001E3080
// tool: the portal's starter code (no AI)
// sub_001E3080 (0x001E3080, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003AA674;
extern "C" float DAT_004626B0;

int __cdecl sub_001E3080(void)
{
    if (DAT_004626B0 >= DAT_003AA674) {
        return 1;
    }
    return 0;
}
