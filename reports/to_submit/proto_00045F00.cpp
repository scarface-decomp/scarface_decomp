// bin: proto
// va: 0x00045F00
// what: 
// tool: the portal's starter code (no AI)

// renderer::GamePlayScene::vfunc_03 (Proto 0x00045F00, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
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
    virtual void vfunc_09();
};

namespace renderer {

class GamePlayScene
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    char m_pad04[0xC];
    bool m_Field10; // +0x10
    char m_pad11[0xF];
    Field20* m_Field20; // +0x20
};

void GamePlayScene::vfunc_03()
{
    if (m_Field10) {
        m_Field20->vfunc_09();
        return;
    }
}

}
