// bin: proto
// va: 0x0019B9C0
// what: 
// tool: the portal's starter code (no AI)

// sub_0019B9C0 (Proto 0x0019B9C0, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0019BE00(int, int, int);
};

int __cdecl sub_0019B9C0(int a1)
{
    int local_4, local_8;

    if (a1) {
        ((Object*)a1)->sub_0019BE00((int)(&local_4), (int)(&a1), (int)(&local_8));
        return a1;
    }
    return 0;
}
