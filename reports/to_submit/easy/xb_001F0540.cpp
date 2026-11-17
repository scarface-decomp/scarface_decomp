// bin: xb
// va: 0x001F0540
// tool: the portal's starter code (no AI)
// sub_001F0540 (0x001F0540, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0043EBC4;
extern "C" float DAT_0043EBC8;
extern "C" float DAT_0043EBCC;

int __cdecl sub_001F0540(int a1)
{
    DAT_0043EBC4 = *(float*)a1;
    DAT_0043EBC8 = *(float*)(a1 + 4);
    DAT_0043EBCC = *(float*)(a1 + 8);
    return a1;
}
