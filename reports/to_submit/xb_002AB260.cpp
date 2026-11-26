// bin: xb
// va: 0x002AB260
// what: Queues a request that calls the caller's thread back once this file's earlier requests are done.
// tool: Claude (from SPEC-019)

struct Thread;
Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void* __cdecl sub_002A9880(unsigned int size);      // the request classes' allocator
void* __cdecl sub_002AAEA0(unsigned int size);      // core::File's allocator
// Splits a path into its parts: the directory, the extension and two pointers into the name.
void __cdecl sub_00251220(const char* name, char* directory, char* extension, const char** tail, const char** full);

namespace core
{
    class Request;
    class File;
    class InstanceDrive;

    // The reference-counted start of every drive and file interface.
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // The lock every drive and file object has as its second part.
    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The real drive (SPEC-017): only what these classes use of it.
    class Drive
    {
    public:
        virtual void AddRef();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int GetCapabilities();     // slot 8; bit 7: names are used whole, with their directory
        void sub_002AC690(Request* request, int priority, bool atHead);     // queue a request on the drive's thread
        bool sub_002AC5B0();    // whether the drive is in its error state
        int sub_002AC3E0();     // the drive's last error
    };

    class FileCompletionRequest
    {
    public:
        FileCompletionRequest* sub_002AA650(Thread* thread, File* file, int a, int b);     // the constructor
        char m_Data[0x18];
    };

    class IFile : public IRefCount
    {
    };

    // An open file on a drive: each call becomes a request queued on the drive.
    class File : public IFile, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_19(int a, int b);

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C
        int m_Priority;         // +0x10
        int m_LastError;        // +0x14
        int m_Outstanding;      // +0x18
        bool m_Open;            // +0x1C
        bool m_Field1D;         // +0x1D
        char m_Name[0x101];     // +0x1E
        int m_Field120;         // +0x120
        int m_Field124;         // +0x124
        int m_Field128;         // +0x128
        char m_Field12C[0x34];  // +0x12C
        bool m_Field160;        // +0x160
        int m_Field164;         // +0x164
    };

}

void core::File::vfunc_19(int a, int b)
{
    FileCompletionRequest* memory = (FileCompletionRequest*)sub_002A9880(sizeof(FileCompletionRequest));
    FileCompletionRequest* request = memory ? memory->sub_002AA650(sub_00283EB0(), this, a, b) : 0;
    m_Drive->sub_002AC690((Request*)request, m_Priority, false);
}
