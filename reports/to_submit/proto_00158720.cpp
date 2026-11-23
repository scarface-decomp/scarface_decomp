// bin: proto
// va: 0x00158720
// what: 
// tool: the portal's starter code (no AI)

// sub_00158720 (Proto 0x00158720, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000BF460(int);
};

int __cdecl sub_00158720(int a1)
{
    int r_eax;

    r_eax = a1;
    if (a1) {
        if (!*(int*)(r_eax + 392)) goto L_19;
        r_eax = ((Object*)*(int*)(r_eax + 392))->sub_000BF460(0);
    }
L_19:
    return r_eax;
}
