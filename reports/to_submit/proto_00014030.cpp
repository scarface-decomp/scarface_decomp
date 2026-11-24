// bin: proto
// va: 0x00014030
// what: 
// tool: the portal's starter code (no AI)

// sub_00014030 (Proto 0x00014030, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0008D4C0(int);
};

extern "C" Object DAT_00441498;

int __cdecl sub_00014030(int a1)
{
    int r_eax;

    r_eax = a1;
    if (a1) {
        r_eax = DAT_00441498.sub_0008D4C0(a1);
    }
    return r_eax;
}
