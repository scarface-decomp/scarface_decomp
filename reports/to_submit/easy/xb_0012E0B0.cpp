// bin: xb
// va: 0x0012E0B0
// tool: the portal's starter code (no AI)
// sub_0012E0B0 (0x0012E0B0, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D584;
extern "C" int DAT_0048A010;
extern "C" int DAT_0048A018;
extern "C" float DAT_0048A01C;

float __stdcall sub_0012E0B0(int a1)
{
    int r_eax, r_ecx;

    r_eax = a1;
    if (a1 < 0) {
        r_ecx = DAT_0048A010;
        r_eax += r_ecx;
    }
    r_ecx = *(int*)(((int)&DAT_0048A018) + (r_eax * 8));
    if (r_ecx == 2) {
        return *(float*)(((int)&DAT_0048A01C) + (r_eax * 8));
    }
    if (r_ecx == 1) {
        return (float)*(int*)(((int)&DAT_0048A01C) + (r_eax * 8));
    }
    return DAT_0039D584;
}
