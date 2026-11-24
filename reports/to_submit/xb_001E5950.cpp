// bin: xb
// va: 0x001E5950
// what: Sets the script field mission of PropSpawnObject (the accessor its field table registers).
// how: shape
// tool: the portal's starter code (no AI)

// sub_001E5950 (0x001E5950, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001E3DB0(int, int);
};

extern "C" void __cdecl sub_0021F520(int, int, int);

void __cdecl sub_001E5950(int a1, int a2)
{
    int local_4, local_8;

    local_4 = 0;
    local_8 = 1;
    sub_0021F520(a2, (int)(&local_4), (int)(&local_8));
    ((Object*)a1)->sub_001E3DB0(local_4, local_8);
}
