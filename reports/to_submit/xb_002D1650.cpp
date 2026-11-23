// bin: xb
// va: 0x002D1650
// what: 
// tool: the portal's starter code (no AI)

// sub_002D1650 (0x002D1650, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004C0178;
extern "C" int DAT_004C017C;
extern "C" int DAT_004C0180;

int __cdecl sub_002D1650(int a1)
{
    int t1;

    DAT_004C0178 = *(int*)a1;
    DAT_004C017C = *(int*)(a1 + 4);
    t1 = *(int*)(a1 + 8);
    DAT_004C0180 = *(int*)(a1 + 8);
    return t1;
}
