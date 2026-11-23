// bin: proto
// va: 0x001EF070
// what: 
// tool: the portal's starter code (no AI)

// sub_001EF070 (Proto 0x001EF070, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001E68D0(int);
};

extern "C" int DAT_00462ED0;

void __cdecl sub_001EF070(int a1)
{
    ((Object*)DAT_00462ED0)->sub_001E68D0(a1);
}
