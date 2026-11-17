// bin: xb
// va: 0x00021590
// tool: the portal's starter code (no AI)
// sub_00021590 (0x00021590, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __stdcall sub_000213F0(int, int);

int __stdcall sub_00021590(int a1, int a2)
{
    int r_eax;

    r_eax = a1;
    if (!a1) {
        r_eax = a2;
        *(float*)(r_eax + 8) = 0.0f;
        *(float*)(r_eax + 4) = 0.0f;
        *(float*)r_eax = 0.0f;
        return r_eax;
    }
    r_eax += 100;
    a1 = r_eax;
    return sub_000213F0(a1, a2);
}
