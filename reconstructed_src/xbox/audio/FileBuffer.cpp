// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/FileBuffer.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::WmaDecoderStream::FileBuffer::vfunc_02 (0x00026DA0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Decrements the reference count at +0x08 and deletes the FileBuffer when it reaches zero.
// ============================================================================
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

