// bin: xb
// va: 0x00216750
// what: 
// tool: the portal's starter code (no AI)

// sub_00216750 (0x00216750, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00217380();
};

bool __cdecl sub_00216750(int a1)
{
    if (((Object*)a1)->sub_00217380()) {
        return *(bool*)(((Object*)a1)->sub_00217380() + 1598);
    }
    return false;
}
