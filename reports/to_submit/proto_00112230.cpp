// bin: proto
// va: 0x00112230
// what: 
// tool: the portal's starter code (no AI)

// sub_00112230 (Proto 0x00112230, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD94;
extern "C" int DAT_0045C1E8;
extern "C" int DAT_0045C1F0;
extern "C" float DAT_0045C1F4;

float __stdcall sub_00112230(int a1)
{
    int r_eax, r_ecx;

    r_eax = a1;
    if (a1 < 0) {
        r_ecx = DAT_0045C1E8;
        r_eax += r_ecx;
    }
    r_ecx = *(int*)(((int)&DAT_0045C1F0) + (r_eax * 8));
    if (r_ecx == 2) {
        return *(float*)(((int)&DAT_0045C1F4) + (r_eax * 8));
    }
    if (r_ecx == 1) {
        return (float)*(int*)(((int)&DAT_0045C1F4) + (r_eax * 8));
    }
    return DAT_0037CD94;
}
