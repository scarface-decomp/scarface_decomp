// bin: proto
// va: 0x001E6CE0
// tool: the portal's starter code (no AI)
// sub_001E6CE0 (0x001E6CE0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00027240(int);
    int sub_00029460();
    int sub_0008E380();
};

class Class_001E6CE0
{
public:
    int sub_001E6CE0();
    char m_pad00[0x48];
    int m_Field48; // +0x48
};

int Class_001E6CE0::sub_001E6CE0()
{
    int r_eax, r_ebx, r_edi, r_esi;

    r_edi = (int)(&m_Field48);
    r_ebx = 4;
    do {
        r_eax = *(int*)r_edi;
        r_eax = ((Object*)r_eax + 48)->sub_0008E380();
        r_esi = (short)((unsigned short)r_eax);
        if (r_esi) {
            do {
                r_esi -= 1;
                r_eax = ((Object*)*(int*)r_edi)->sub_00027240(r_esi);
                if (r_eax) {
                    r_eax = ((Object*)r_eax)->sub_00029460();
                }
            } while (r_esi);
        }
        r_edi += 20;
        r_ebx -= 1;
    } while (r_ebx);
    return r_eax;
}
