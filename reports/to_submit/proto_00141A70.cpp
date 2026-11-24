// bin: proto
// va: 0x00141A70
// what: 
// tool: the portal's starter code (no AI)

// sub_00141A70 (Proto 0x00141A70, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001337C0(int, int);
};

extern "C" char sub_00141A40[];
extern "C" int __cdecl sub_0008E670(int, int, int, int);

int __cdecl sub_00141A70(int a1, int a2, int a3)
{
    int r_eax;

    r_eax = a3;
    r_eax = *(int*)(r_eax + 8);
    if (*(unsigned char*)r_eax) {
        r_eax = sub_0008E670(15, r_eax, 0, 0);
        r_eax = ((Object*)a1)->sub_001337C0((int)sub_00141A40, r_eax);
    }
    return r_eax;
}
