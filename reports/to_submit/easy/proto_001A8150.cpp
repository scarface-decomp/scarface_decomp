// bin: proto
// va: 0x001A8150
// tool: the portal's starter code (no AI)
// sub_001A8150 (0x001A8150, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001E9CD0(int, int, int, int);
};

extern "C" float DAT_003902F0;
extern "C" int DAT_00462ED0;

class Class_001A8150
{
public:
    int sub_001A8150(int a1, int a2, int a3, int a4, int a5);
    char m_pad00[0xA8];
    int m_FieldA8; // +0xA8
};

int Class_001A8150::sub_001A8150(int a1, int a2, int a3, int a4, int a5)
{
    int r_eax, t1;

    r_eax = 1;
    t1 = *(int*)m_FieldA8;
    if (*(int*)m_FieldA8) {
        r_eax = *(char*)(t1 + 22);
    }
    r_eax = ((Object*)DAT_00462ED0)->sub_001E9CD0(r_eax, a2, a3, a4);
    if (a5) {
        *(float*)a5 = DAT_003902F0;
    }
    return r_eax;
}
