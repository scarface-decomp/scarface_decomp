// bin: proto
// va: 0x000CF5A0
// what: 
// tool: the portal's starter code (no AI)

// sub_000CF5A0 (Proto 0x000CF5A0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00243D90(int, int, int);
};

extern "C" float DAT_0037CE50;

class Class_000CF5A0
{
public:
    int sub_000CF5A0(int a1, int a2, int a3);
    char m_pad00[0x30];
    int m_Field30; // +0x30
};

int Class_000CF5A0::sub_000CF5A0(int a1, int a2, int a3)
{
    int t1;

    t1 = m_Field30;
    if (m_Field30) {
        return ((Object*)t1)->sub_00243D90(a1, a2, a3);
    }
    *(float*)(a3 + 8) = 0.0f;
    *(float*)(a3 + 4) = 0.0f;
    *(float*)a3 = 0.0f;
    *(float*)(a3 + 12) = DAT_0037CE50;
    return a3;
}
