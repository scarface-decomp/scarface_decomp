// bin: proto
// va: 0x000D8F20
// what: 
// tool: the portal's starter code (no AI)

// sub_000D8F20 (Proto 0x000D8F20, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045A0EC;
extern "C" bool __cdecl sub_0008E600(int);

void __cdecl sub_000D8F20(int a1, int a2, int a3)
{
    int t1;

    t1 = DAT_0045A0EC;
    *(unsigned char*)(t1 + 133) = sub_0008E600(*(int*)(a3 + 4));
}
