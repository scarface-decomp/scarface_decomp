// bin: proto
// va: 0x001DADC0
// what: 
// tool: the portal's starter code (no AI)

// sub_001DADC0 (Proto 0x001DADC0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001DB8F0();
};

bool __cdecl sub_001DADC0(int a1)
{
    if (((Object*)a1)->sub_001DB8F0()) {
        return *(bool*)(((Object*)a1)->sub_001DB8F0() + 1558);
    }
    return false;
}
