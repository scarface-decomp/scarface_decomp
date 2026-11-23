// bin: xb
// va: 0x002160F0
// what: 
// tool: the portal's starter code (no AI)

// sub_002160F0 (0x002160F0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00217470();
};

bool __cdecl sub_002160F0(int a1)
{
    return *(bool*)(((Object*)a1)->sub_00217470() + 1324);
}
