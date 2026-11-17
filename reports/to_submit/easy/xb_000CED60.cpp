// bin: xb
// va: 0x000CED60
// tool: the portal's starter code (no AI)
// sub_000CED60 (0x000CED60, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004870D0;

int __cdecl sub_000CED60(void)
{
    return *(int*)(DAT_004870D0 + 624) != 0;
}
