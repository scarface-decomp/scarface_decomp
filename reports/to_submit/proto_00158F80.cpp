// bin: proto
// va: 0x00158F80
// what: 
// tool: the portal's starter code (no AI)

// sub_00158F80 (Proto 0x00158F80, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0014A960();
};

int __cdecl sub_00158F80(int a1)
{
    if (((Object*)a1)->sub_0014A960()) {
        return *(int*)(((Object*)a1)->sub_0014A960() + 16);
    }
    return 0;
}
