// bin: xb
// va: 0x0001E3B0
// tool: the portal's starter code (no AI)
// sub_0001E3B0 (0x0001E3B0, 93 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0001FF70(int);
    void sub_00098B70(int);
};

extern "C" bool __cdecl sub_0001EEC0(void);
extern "C" int __cdecl sub_0002AC90(int);

class Class_0001E3B0
{
public:
    bool sub_0001E3B0(int a1);
    char m_pad00[0x2C];
    int m_Field2C; // +0x2C
    char m_pad30[0x4];
    short m_Field34; // +0x34
};

bool Class_0001E3B0::sub_0001E3B0(int a1)
{
    int r_ebx, r_edi;
    short t5;

    r_edi = 0;
    if (m_Field34 > 0) {
        r_ebx = a1;
        do {
            ((Object*)(int)(&a1))->sub_00098B70((int)this);
            ((Object*)*(int*)(m_Field2C + (((short)((unsigned short)r_edi)) * 4)))->sub_0001FF70(r_ebx);
            if (sub_0001EEC0()) goto L_55;
            if (!sub_0002AC90(a1)) goto L_55;
            t5 = m_Field34;
            r_edi += 1;
        } while (r_edi < t5);
    }
    return true;
L_55:
    return false;
}
