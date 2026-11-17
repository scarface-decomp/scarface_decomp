// bin: proto
// va: 0x002AFCB0
// tool: the portal's starter code (no AI)
// sub_002AFCB0 (0x002AFCB0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_004915C4;
extern "C" void __cdecl sub_002AFF80(int);

void __cdecl sub_002AFCB0(int a1)
{
    sub_002AFF80(a1);
    DAT_004915C4 = (unsigned char)(DAT_004915C4 | 1);
}
