// bin: xb
// va: 0x001E11F0
// tool: the portal's starter code (no AI)
// sub_001E11F0 (0x001E11F0, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00225B80(int, int, int, int, int);
};

extern "C" float DAT_003C76A4;
extern "C" int DAT_00491EF8;

class Class_001E11F0
{
public:
    int sub_001E11F0(int a1, int a2, int a3, int a4, int a5);
    char m_pad00[0xAC];
    int m_FieldAC; // +0xAC
};

int Class_001E11F0::sub_001E11F0(int a1, int a2, int a3, int a4, int a5)
{
    int r_eax, t1;

    r_eax = 1;
    t1 = *(int*)m_FieldAC;
    if (*(int*)m_FieldAC) {
        r_eax = *(unsigned char*)(t1 + 31);
        r_eax >>= 4;
    }
    r_eax = ((Object*)DAT_00491EF8)->sub_00225B80(r_eax, a2, a3, a4, 0);
    if (a5) {
        *(float*)a5 = DAT_003C76A4;
    }
    return r_eax;
}
