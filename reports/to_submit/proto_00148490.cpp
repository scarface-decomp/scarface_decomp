// bin: proto
// va: 0x00148490
// what: 
// tool: the portal's starter code (no AI)

// sub_00148490 (Proto 0x00148490, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045A0EC;
extern "C" int DAT_0045CC6C;
extern "C" int DAT_0045CC70;

int __cdecl sub_00148490(void)
{
    int r_eax;

    r_eax = DAT_0045A0EC;
    r_eax = *(int*)(r_eax + 44);
    if ((unsigned int)(DAT_0045CC70 + 4000) < (unsigned int)r_eax) {
        DAT_0045CC6C = r_eax;
    }
    return r_eax;
}
