// bin: proto
// va: 0x00147D90
// what: 
// tool: the portal's starter code (no AI)

// sub_00147D90 (Proto 0x00147D90, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00145EB0();
};

extern "C" int __cdecl sub_00145FE0(void);

bool __cdecl sub_00147D90(void)
{
    int t1;

    t1 = sub_00145FE0();
    if (t1) {
        return ((Object*)t1)->sub_00145EB0();
    }
    return false;
}
