// bin: proto
// va: 0x001B6340
// tool: the portal's starter code (no AI)
// sub_001B6340 (0x001B6340, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0041833C;
extern "C" float DAT_00418340;
extern "C" float DAT_00418344;

int __cdecl sub_001B6340(int a1)
{
    DAT_0041833C = *(float*)a1;
    DAT_00418340 = *(float*)(a1 + 4);
    DAT_00418344 = *(float*)(a1 + 8);
    return a1;
}
