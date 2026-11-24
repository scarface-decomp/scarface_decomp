// bin: proto
// va: 0x00147DB0
// what: 
// tool: the portal's starter code (no AI)

// sub_00147DB0 (Proto 0x00147DB0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00145F80();
};

extern "C" int __cdecl sub_00145FE0(void);

bool __cdecl sub_00147DB0(void)
{
    int t1;

    t1 = sub_00145FE0();
    if (t1) {
        return ((Object*)t1)->sub_00145F80();
    }
    return false;
}
