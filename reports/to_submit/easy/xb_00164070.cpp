// bin: xb
// va: 0x00164070
// tool: the portal's starter code (no AI)
// sub_00164070 (0x00164070, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00161030();
};

extern "C" int __cdecl sub_001611A0(void);

bool __cdecl sub_00164070(void)
{
    int t1;

    t1 = sub_001611A0();
    if (t1) {
        return ((Object*)t1)->sub_00161030();
    }
    return false;
}
