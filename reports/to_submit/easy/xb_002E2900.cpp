// bin: xb
// va: 0x002E2900
// tool: the portal's starter code (no AI)
// sub_002E2900 (0x002E2900, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_004C0530;
extern "C" void __cdecl sub_002E2BE0(int);

void __cdecl sub_002E2900(int a1)
{
    sub_002E2BE0(a1);
    DAT_004C0530 = (unsigned char)(DAT_004C0530 | 1);
}
