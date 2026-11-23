// bin: xb
// va: 0x00248D40
// what: 
// tool: the portal's starter code (no AI)

// sub_00248D40 (0x00248D40, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00493B78[];
extern "C" int DAT_00493B9C;

int __cdecl sub_00248D40(int a1)
{
    int t1;

    t1 = DAT_00493B9C;
    DAT_00493B78[DAT_00493B9C] = a1;
    DAT_00493B9C = t1 + 1;
    return t1 + 1;
}
