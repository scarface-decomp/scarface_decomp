// bin: xb
// va: 0x00077870
// tool: the portal's starter code (no AI)
// sub_00077870 (0x00077870, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00480FA8;

float __cdecl sub_00077870(int a1)
{
    return *(float*)(DAT_00480FA8 + (a1 * 4) + 3960);
}
