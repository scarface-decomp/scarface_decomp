// bin: xb
// va: 0x00329310
// what: 
// tool: the portal's starter code (no AI)

// sub_00329310 (0x00329310, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D7758[];
extern "C" int DAT_0045A8C0;
extern "C" int DAT_0045A8C8;
extern "C" void __cdecl sub_00027600(int);

void __cdecl sub_00329310(void)
{
    int t1;

    t1 = DAT_0045A8C8;
    DAT_0045A8C0 = (int)DAT_003D7758;
    if (DAT_0045A8C8) {
        sub_00027600(t1);
    }
}
