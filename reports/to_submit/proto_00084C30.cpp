// bin: proto
// va: 0x00084C30
// what: 
// tool: the portal's starter code (no AI)

// sub_00084C30 (Proto 0x00084C30, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00453C5C;
extern "C" void __cdecl sub_00025160(int);

void __cdecl sub_00084C30(void)
{
    int t1;

    t1 = DAT_00453C5C;
    if (DAT_00453C5C) {
        sub_00025160(t1);
    }
}
