// bin: proto
// va: 0x00193510
// what: 
// tool: the portal's starter code (no AI)

// sub_00193510 (Proto 0x00193510, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00192620(int);
};

extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_00193510(int a1, int a2, int a3)
{
    if (a1) {
        ((Object*)a1)->sub_00192620(sub_002C96FE(*(int*)(a3 + 8)));
    }
}
