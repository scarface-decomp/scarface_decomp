// bin: proto
// va: 0x00022050
// what: 
// tool: the portal's starter code (no AI)

// FrontEndManager::DrawHandler::vfunc_00 (Proto 0x00022050, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00021F90();
    int sub_0020BC60();
};

extern "C" bool DAT_003F56B0;
extern "C" Object DAT_003F56B8;
extern "C" int DAT_00446A90;

namespace FrontEndManager {

class DrawHandler
{
public:
    virtual void vfunc_00();
};

void DrawHandler::vfunc_00()
{
    int r_eax;

    r_eax = DAT_003F56B0;
    if ((unsigned char)r_eax) {
        if (DAT_00446A90) {
            r_eax = ((Object*)DAT_00446A90)->sub_0020BC60();
        }
        DAT_003F56B8.sub_00021F90();
        return;
    }
}

}
