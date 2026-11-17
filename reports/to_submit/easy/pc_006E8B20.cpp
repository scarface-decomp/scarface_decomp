// bin: pc
// va: 0x006E8B20
// tool: the portal's starter code (no AI)
// sub_006E8B20 (0x006E8B20, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006E8B20
{
public:
    int sub_006E8B20(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

int Class_006E8B20::sub_006E8B20(int a1)
{
    int r_eax, r_edi, r_esi;

    r_eax = *(int*)a1;
    r_esi = *(int*)(r_eax + 4);
    *(int*)a1 = r_esi;
    r_esi = *(int*)(r_eax + 4);
    r_edi = (int)(&m_Field04);
    if (r_esi != ((int)(&m_Field04))) {
        *(int*)(r_esi + 8) = a1;
    }
    r_esi = *(int*)(a1 + 8);
    *(int*)(r_eax + 8) = r_esi;
    r_esi = *(int*)(a1 + 8);
    if (r_esi == r_edi) {
        m_Field00 = r_eax;
        *(int*)(r_eax + 4) = a1;
        *(int*)(a1 + 8) = r_eax;
        return r_eax;
    }
    if (a1 == *(int*)r_esi) {
        *(int*)r_esi = r_eax;
        *(int*)(r_eax + 4) = a1;
        *(int*)(a1 + 8) = r_eax;
        return r_eax;
    }
    *(int*)(r_esi + 4) = r_eax;
    *(int*)(r_eax + 4) = a1;
    *(int*)(a1 + 8) = r_eax;
    return r_eax;
}
