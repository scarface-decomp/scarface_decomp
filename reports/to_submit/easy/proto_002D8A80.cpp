// bin: proto
// va: 0x002D8A80
// tool: the portal's starter code (no AI)
// sub_002D8A80 (0x002D8A80, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002CB42A(int);

void __stdcall sub_002D8A80(int a1)
{
    int r_eax, r_ecx;

    r_eax = a1;
    if (a1) {
        r_ecx = *(unsigned char*)(r_eax + -1);
        if (*(unsigned char*)(r_eax + -2) == 3) {
            a1 = a1 - r_ecx;
            ((void (__stdcall*)(int))*(int*)(r_eax + -8))(a1);
            return;
        }
        r_eax -= r_ecx;
        sub_002CB42A(r_eax);
    }
}
