// bin: xb
// va: 0x00322550
// what: 
// tool: the portal's starter code (no AI)

// sub_00322550 (0x00322550, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0046C0D0;
extern "C" void __cdecl sub_00027600(int);

void __cdecl sub_00322550(void)
{
    int t1;

    t1 = DAT_0046C0D0;
    if (DAT_0046C0D0) {
        sub_00027600(t1);
    }
}
