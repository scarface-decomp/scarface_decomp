// bin: xb
// va: 0x001640F0
// tool: the portal's starter code (no AI)
// sub_001640F0 (0x001640F0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00161070(int);
};

extern "C" int __cdecl sub_001611A0(void);

bool __stdcall sub_001640F0(int a1)
{
    int t1;

    t1 = sub_001611A0();
    if (t1) {
        return ((Object*)t1)->sub_00161070(a1);
    }
    return false;
}
