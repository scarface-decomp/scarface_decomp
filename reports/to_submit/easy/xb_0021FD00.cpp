// bin: xb
// va: 0x0021FD00
// tool: the portal's starter code (no AI)
// sub_0021FD00 (0x0021FD00, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0049153F;

void __cdecl sub_0021FD00(bool a1)
{
    DAT_0049153F = (unsigned char)(DAT_0049153F ^ ((unsigned char)(((unsigned char)(DAT_0049153F ^ a1)) & 1)));
}
