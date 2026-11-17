// bin: xb
// va: 0x00288240
// tool: the portal's starter code (no AI)
// sub_00288240 (0x00288240, 84 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    void sub_00287E70(int, int);
};

extern "C" void __cdecl sub_00287D80(int, int, int, int);

int __cdecl sub_00288240(int a1, int a2, int a3, int a4, int a5)
{
    int local_10, local_8, local_C;

    local_C = 0;
    local_8 = 0;
    local_10 = 0;
    ((Object*)a2)->sub_00287E70(a5, (int)(&local_C));
    ((Object*)a3)->sub_00287E70(a5, (int)(&local_8));
    sub_00287D80((int)(&local_10), (int)(&local_C), (int)(&local_8), a4);
    *(int*)a1 = local_10;
    return a1;
}
