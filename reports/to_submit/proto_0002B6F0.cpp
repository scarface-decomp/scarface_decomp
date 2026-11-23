// bin: proto
// va: 0x0002B6F0
// what: 
// tool: the portal's starter code (no AI)

// sub_0002B6F0 (Proto 0x0002B6F0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual int vfunc_00();
};

int __cdecl sub_0002B6F0(int a1)
{
    ((Object*)a1)->vfunc_00();
    return *(int*)(((Object*)a1)->vfunc_00() + 20);
}
