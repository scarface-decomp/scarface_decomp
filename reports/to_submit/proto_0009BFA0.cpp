// bin: proto
// va: 0x0009BFA0
// what: 
// tool: the portal's starter code (no AI)

// sub_0009BFA0 (Proto 0x0009BFA0, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field38
{
    int sub_0007D3B0(int);
};

struct Object
{
    int sub_0009B410(int, int);
};

extern "C" void __cdecl sub_0007CE90(void);

class Class_0009BFA0
{
public:
    int sub_0009BFA0(int a1);
    char m_pad00[0x30];
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    Field38 m_Field38; // +0x38
};

int Class_0009BFA0::sub_0009BFA0(int a1)
{
    int r_eax;

    sub_0007CE90();
    r_eax = m_Field34;
    if (r_eax) {
        if (!*(unsigned char*)r_eax) goto L_27;
        r_eax = ((Object*)a1)->sub_0009B410(r_eax, 1);
        m_Field30 = r_eax;
        return r_eax;
    }
L_27:
    r_eax = a1;
    r_eax = *(int*)(r_eax + 4);
    if (r_eax) {
        r_eax = m_Field38.sub_0007D3B0(r_eax);
    }
    return r_eax;
}
