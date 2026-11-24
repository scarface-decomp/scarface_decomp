// bin: xb
// va: 0x00230890
// what: 
// tool: the portal's starter code (no AI)

// sub_00230890 (0x00230890, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00491EF8;
extern "C" bool __cdecl sub_00099BC0(int);

void __cdecl sub_00230890(int a1, int a2, int a3)
{
    int t1;

    t1 = DAT_00491EF8;
    *(unsigned char*)(t1 + 957) = sub_00099BC0(*(int*)(a3 + 4));
}
