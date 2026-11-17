// bin: proto
// va: 0x0005A590
// tool: the portal's starter code (no AI)
// sub_0005A590 (0x0005A590, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0044AE70;

int __cdecl sub_0005A590(void)
{
    int r_eax, r_ecx, r_edx;

    r_edx = DAT_0044AE70;
    r_eax = 0;
    r_ecx = r_edx;
    do {
        if (*(unsigned short*)r_ecx == 65535) {
            if (!*(int*)(r_ecx + 4)) goto L_2D;
        }
        r_eax += 1;
        r_ecx += 24;
    } while (r_eax < 128);
    r_eax = 0;
    return r_eax;
L_2D:
    r_eax = r_eax + (r_eax * 2);
    r_eax = r_edx + (r_eax * 8);
    return r_eax;
}
