// bin: proto
// va: 0x000FBC90
// what: 
// tool: the portal's starter code (no AI)

// sub_000FBC90 (Proto 0x000FBC90, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045BD1C;
extern "C" bool __cdecl sub_0008E600(int);

void __cdecl sub_000FBC90(int a1, int a2, int a3)
{
    int t1;

    t1 = DAT_0045BD1C;
    *(unsigned char*)(t1 + 4) = sub_0008E600(*(int*)(a3 + 4));
}
