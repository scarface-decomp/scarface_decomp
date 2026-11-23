// bin: proto
// va: 0x001EF020
// what: 
// tool: the portal's starter code (no AI)

// sub_001EF020 (Proto 0x001EF020, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001AF8E0(int);
};

extern "C" int DAT_00460C24;

void __cdecl sub_001EF020(int a1)
{
    ((Object*)DAT_00460C24)->sub_001AF8E0(a1);
}
