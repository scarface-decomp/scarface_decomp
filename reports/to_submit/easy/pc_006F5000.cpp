// bin: pc
// va: 0x006F5000
// tool: the portal's starter code (no AI)
// sub_006F5000 (0x006F5000, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F4F10(int);
};

extern "C" char DAT_007F6D80[];
extern "C" int __cdecl sub_006EE870(int);

int __cdecl sub_006F5000(int a1)
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F6D80);
    if (t1) {
        return ((Object*)t1)->sub_006F4F10(a1);
    }
    return 0;
}
