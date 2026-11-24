// bin: proto
// va: 0x0002B6D0
// what: 
// tool: the portal's starter code (no AI)

// sub_0002B6D0 (Proto 0x0002B6D0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000281A0();
};

int __cdecl sub_0002B6D0(int a1)
{
    int t1;

    t1 = ((Object*)a1)->sub_000281A0();
    if (t1) {
        return *(int*)(t1 + 16);
    }
    return 0;
}
