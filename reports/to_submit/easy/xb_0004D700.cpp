// bin: xb
// va: 0x0004D700
// tool: the portal's starter code (no AI)
// renderer::Scene::vfunc_04 (0x0004D700, 79 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09(int);
};

namespace renderer {

class Scene
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x4];
    bool m_Field10; // +0x10
    char m_pad11[0x7];
    int m_Field18; // +0x18
};

void Scene::vfunc_04(int a1)
{
    int r_ebp, r_ebx, r_esi, t1;

    if (!m_Field10) goto L_4B;
    r_esi = m_Field08;
    r_esi -= m_Field04;
    r_esi >>= 2;
    r_ebp = 0;
    if (r_esi <= 0) goto L_49;
    r_ebx = a1;
L_22:
    t1 = *(int*)(m_Field04 + (r_ebp * 4));
    if (*(int*)(m_Field04 + (r_ebp * 4))) {
        if (!(*(unsigned char*)(t1 + 128) & 16)) goto L_43;
        if (!(m_Field18 & *(int*)(t1 + 84))) goto L_43;
        ((Object*)t1)->vfunc_09(r_ebx);
    }
L_43:
    r_ebp += 1;
    if (r_ebp < r_esi) goto L_22;
L_49:
L_4B:
    ;
}

}
