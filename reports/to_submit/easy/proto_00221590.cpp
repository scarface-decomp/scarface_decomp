// bin: proto
// va: 0x00221590
// tool: the portal's starter code (no AI)
// sub_00221590 (0x00221590, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00025160(int);

void __cdecl sub_00221590(int a1, int a2)
{
    int r_edi, r_esi, t1;

    r_esi = a1;
    r_edi = a2;
    if (a1 != a2) {
        do {
            t1 = *(int*)r_esi;
            if (*(int*)r_esi) {
                sub_00025160(t1);
            }
            r_esi += 16;
        } while (r_esi != r_edi);
    }
}
