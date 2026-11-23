// bin: xb
// va: 0x00322530
// what: 
// tool: the portal's starter code (no AI)

// sub_00322530 (0x00322530, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0046C0C4;
extern "C" void __cdecl sub_00027600(int);

void __cdecl sub_00322530(void)
{
    int t1;

    t1 = DAT_0046C0C4;
    if (DAT_0046C0C4) {
        sub_00027600(t1);
    }
}
