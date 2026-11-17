// bin: xb
// va: 0x00164110
// tool: the portal's starter code (no AI)
// sub_00164110 (0x00164110, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00161150();
};

extern "C" int __cdecl sub_001611A0(void);

bool __cdecl sub_00164110(void)
{
    int t1;

    t1 = sub_001611A0();
    if (t1) {
        return ((Object*)t1)->sub_00161150();
    }
    return false;
}
