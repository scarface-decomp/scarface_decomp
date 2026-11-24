// bin: xb
// va: 0x00270BA0
// what: Returns 1 if the chunk ID parameter matches 0x00015900, otherwise 0.
// tool: Gemini 4 Neon

#pragma optimize("y", off)

extern "C" char sub_00015900[];

namespace pure3d {

class DefaultParticleEmitterHandler
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual unsigned char vfunc_04(int chunkId);
};

#pragma optimize("s", on)
unsigned char DefaultParticleEmitterHandler::vfunc_04(int chunkId)
{
    return chunkId == (int)sub_00015900;
}
#pragma optimize("", on)

}
