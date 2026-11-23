// bin: xb
// va: 0x001BE340
// what: 
// tool: the portal's starter code (no AI)

// sub_001BE340 (0x001BE340, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00195830(int);
    bool sub_0019F7A0(int);
};

extern "C" int DAT_0048C23C;

int __cdecl sub_001BE340(void)
{
    int t1;

    t1 = ((Object*)DAT_0048C23C)->sub_00195830(73);
    if (*(int*)(t1 + 112) == 2) {
        if (!((Object*)t1)->sub_0019F7A0(2)) goto L_26;
        return 1;
    }
L_26:
    return 0;
}
