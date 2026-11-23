// bin: xb
// va: 0x0022E1E0
// what: 
// tool: the portal's starter code (no AI)

// sub_0022E1E0 (0x0022E1E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044E140;
extern "C" int DAT_0049201C;
extern "C" int __cdecl sub_000273D0(int);

int __cdecl sub_0022E1E0(void)
{
    int r_eax, t1;

    r_eax = *(int*)(DAT_0049201C + 92);
    t1 = DAT_0049201C + 92;
    if (r_eax != 2) {
        if (r_eax != 3) goto L_30;
        r_eax = DAT_0044E140;
        r_eax = sub_000273D0(r_eax);
        if (r_eax == -1) goto L_30;
        *(int*)t1 = 1;
    }
L_30:
    return r_eax;
}
