// bin: xb
// va: 0x00026DA0
// what: Decrements the reference count at +0x08 and deletes the FileBuffer when it reaches zero.
// tool: Gemini 4 Neon

namespace audio {
namespace WmaDecoderStream {

class FileBuffer
{
public:
    virtual ~FileBuffer();
    virtual void vfunc_01();
    virtual void vfunc_02();
    char m_pad04[0x4];
    int m_RefCount; // +0x08
};

void FileBuffer::vfunc_02()
{
    if (--m_RefCount == 0) {
        m_RefCount = 0x5DC;
        delete this;
    }
}

}
}
