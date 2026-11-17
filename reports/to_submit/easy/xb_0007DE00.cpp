// bin: xb
// va: 0x0007DE00
// tool: the portal's starter code (no AI)
// sub_0007DE00 (0x0007DE00, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00242D50(int);
};

int __cdecl sub_0007DE00(int a1, int a2)
{
    bool t1;

    t1 = ((Object*)a1)->sub_00242D50(a2);
    if (t1) {
        return t1 | -1;
    }
    return ((Object*)a2)->sub_00242D50(a1) != 0;
}
