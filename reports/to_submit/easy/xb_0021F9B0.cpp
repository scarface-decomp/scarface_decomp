// bin: xb
// va: 0x0021F9B0
// tool: the portal's starter code (no AI)
// sub_0021F9B0 (0x0021F9B0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0049153C;

void __cdecl sub_0021F9B0(bool a1)
{
    DAT_0049153C = (unsigned char)(DAT_0049153C ^ ((unsigned char)(((unsigned char)(DAT_0049153C ^ a1)) & 1)));
}
