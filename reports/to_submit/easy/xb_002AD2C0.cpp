// bin: xb
// va: 0x002AD2C0
// tool: the portal's starter code (no AI)
// sub_002AD2C0 (0x002AD2C0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00251310(int);

class Class_002AD2C0
{
public:
    void sub_002AD2C0(int a1, int a2);
    void sub_002AD0D0(int, int);
};

void Class_002AD2C0::sub_002AD2C0(int a1, int a2)
{
    int r_eax;

    r_eax = a1;
    if (*(unsigned char*)r_eax == 92) {
        r_eax += 1;
    }
    r_eax = sub_00251310(r_eax);
    sub_002AD0D0(r_eax, a2);
}
