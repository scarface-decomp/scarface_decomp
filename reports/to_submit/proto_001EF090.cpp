// bin: proto
// va: 0x001EF090
// what: 
// tool: the portal's starter code (no AI)

// sub_001EF090 (Proto 0x001EF090, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001E68A0(int, int);
};

extern "C" int DAT_00462ED0;

void __cdecl sub_001EF090(int a1, int a2)
{
    ((Object*)DAT_00462ED0)->sub_001E68A0(a1, a2);
}
