// bin: xb
// va: 0x001BD720
// what: 
// tool: the portal's starter code (no AI)

// sub_001BD720 (0x001BD720, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00195830(int);
    void sub_00199660();
};

extern "C" int DAT_0048C23C;

void __cdecl sub_001BD720(void)
{
    int t1;

    t1 = ((Object*)DAT_0048C23C)->sub_00195830(3);
    if (t1) {
        ((Object*)t1)->sub_00199660();
        return;
    }
}
