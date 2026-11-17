// bin: proto
// va: 0x00299010
// tool: the portal's starter code (no AI)
// sub_00299010 (0x00299010, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0029BA30(int, int);

int __cdecl sub_00299010(int a1, int a2)
{
    int local_4, t1;

    t1 = sub_0029BA30(a1, (int)(&local_4));
    *(int*)a2 = local_4;
    return t1;
}
