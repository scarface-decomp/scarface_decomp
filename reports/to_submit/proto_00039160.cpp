// bin: proto
// va: 0x00039160
// what: 
// tool: the portal's starter code (no AI)

// sub_00039160 (Proto 0x00039160, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00036CF0(void);
extern "C" int __cdecl sub_0006C370(int, int);

void __cdecl sub_00039160(int a1, int a2, int a3)
{
    int t1;

    t1 = sub_0006C370(*(int*)(a3 + 4), 0);
    *(int*)(sub_00036CF0() + 96) = t1;
}
