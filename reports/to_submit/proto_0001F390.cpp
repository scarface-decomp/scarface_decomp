// bin: proto
// va: 0x0001F390
// what: 
// tool: the portal's starter code (no AI)

// sub_0001F390 (Proto 0x0001F390, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __stdcall sub_0001F1F0(int, int);

int __stdcall sub_0001F390(int a1, int a2)
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
    r_eax += 96;
    a1 = r_eax;
    return sub_0001F1F0(a1, a2);
}
