// bin: xb
// va: 0x00216100
// what: 
// tool: the portal's starter code (no AI)

// sub_00216100 (0x00216100, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00217470();
};

bool __cdecl sub_00216100(int a1)
{
    return *(int*)(((Object*)a1)->sub_00217470() + 1400) == 3;
}
