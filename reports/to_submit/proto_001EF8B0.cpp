// bin: proto
// va: 0x001EF8B0
// what: 
// tool: the portal's starter code (no AI)

// sub_001EF8B0 (Proto 0x001EF8B0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001F0100(int);
};

extern "C" int DAT_004635CC;

void __cdecl sub_001EF8B0(int a1, int a2, int a3)
{
    ((Object*)DAT_004635CC)->sub_001F0100(*(int*)(a3 + 4));
}
