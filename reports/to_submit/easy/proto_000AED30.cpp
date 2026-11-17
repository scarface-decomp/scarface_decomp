// bin: proto
// va: 0x000AED30
// tool: the portal's starter code (no AI)
// sub_000AED30 (0x000AED30, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045930C;
extern "C" void __cdecl sub_00025160(int);

void __cdecl sub_000AED30(void)
{
    int r_esi, t1, t2;

    r_esi = DAT_0045930C;
    t1 = DAT_0045930C;
    if (DAT_0045930C) {
        *(int*)(t1 + 4) = *(int*)t1;
        t2 = *(int*)r_esi;
        if (*(int*)r_esi) {
            sub_00025160(t2);
        }
        sub_00025160(r_esi);
    }
    DAT_0045930C = 0;
}
