// bin: pc
// va: 0x006F13E0
// tool: the portal's starter code (no AI)
// sub_006F13E0 (0x006F13E0, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F6BD0;

int __cdecl sub_006F13E0(int a1, int a2)
{
    return ((((unsigned int)*(int*)a1) >> 4) & 31) * *(int*)(((int)&DAT_007F6BD0) + (((*(int*)a1 & 15) + ((*(int*)a1 & 15) * 2)) * 8)) * a2;
}
