// bin: pc
// va: 0x006F13C0
// tool: the portal's starter code (no AI)
// sub_006F13C0 (0x006F13C0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F6BCC;

int __cdecl sub_006F13C0(int a1)
{
    return *(int*)(((int)&DAT_007F6BCC) + (((*(int*)a1 & 15) + ((*(int*)a1 & 15) * 2)) * 8));
}
