// bin: proto
// va: 0x000390D0
// what: 
// tool: the portal's starter code (no AI)

// sub_000390D0 (Proto 0x000390D0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00036BD0();
};

extern "C" int __cdecl sub_00036CF0(void);

void __cdecl sub_000390D0(void)
{
    ((Object*)sub_00036CF0())->sub_00036BD0();
}
