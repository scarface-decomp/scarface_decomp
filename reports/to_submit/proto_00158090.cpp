// bin: proto
// va: 0x00158090
// what: 
// tool: the portal's starter code (no AI)

// sub_00158090 (Proto 0x00158090, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00197EB0(int, int);
};

extern "C" int __cdecl sub_00197D90(void);

bool __cdecl sub_00158090(int a1)
{
    int t1;

    t1 = sub_00197D90();
    if (t1) {
        ((Object*)t1)->sub_00197EB0(a1, 1);
    }
    return true;
}
