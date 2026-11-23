// bin: proto
// va: 0x00055F80
// what: 
// tool: the portal's starter code (no AI)

// sub_00055F80 (Proto 0x00055F80, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00059280(int);

int __cdecl sub_00055F80(int a1, int a2, int a3)
{
    int r_eax;

    r_eax = a3;
    r_eax = *(int*)(r_eax + 4);
    r_eax = sub_00059280(r_eax);
    if (((unsigned short)r_eax) == 65535) {
        r_eax |= -1;
        return r_eax;
    }
    r_eax = (unsigned short)((unsigned short)r_eax);
    return r_eax;
}
