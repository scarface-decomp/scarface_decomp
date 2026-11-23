// bin: xb
// va: 0x001D34A0
// what: 
// tool: the portal's starter code (no AI)

// sub_001D34A0 (0x001D34A0, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001D3920(int, int, int);
};

int __cdecl sub_001D34A0(int a1)
{
    int local_4, local_8;

    if (a1) {
        ((Object*)a1)->sub_001D3920((int)(&local_4), (int)(&a1), (int)(&local_8));
        return a1;
    }
    return 0;
}
