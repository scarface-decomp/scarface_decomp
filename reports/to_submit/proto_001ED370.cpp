// bin: proto
// va: 0x001ED370
// what: 
// tool: the portal's starter code (no AI)

// sub_001ED370 (Proto 0x001ED370, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00427840;
extern "C" int DAT_00462F98;
extern "C" int __cdecl sub_00024F80(int);

int __cdecl sub_001ED370(void)
{
    int r_eax, t1;

    r_eax = *(int*)(DAT_00462F98 + 92);
    t1 = DAT_00462F98 + 92;
    if (r_eax != 2) {
        if (r_eax != 3) goto L_30;
        r_eax = DAT_00427840;
        r_eax = sub_00024F80(r_eax);
        if (r_eax == -1) goto L_30;
        *(int*)t1 = 0;
    }
L_30:
    return r_eax;
}
