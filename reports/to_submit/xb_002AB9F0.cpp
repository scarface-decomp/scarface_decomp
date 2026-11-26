// bin: xb
// va: 0x002AB9F0
// what: Queues a request for the next entry of the open directory search.
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

    class DriveFindNextRequest
    {
    public:
        DriveFindNextRequest* sub_002AAD00(InstanceDrive* drive, int a);     // the constructor
        char m_Data[0x10];
    };

    class IDrive : public IRefCount
    {
    };

    // One user's handle on a drive: it turns each call into a request queued on the real drive.
    class InstanceDrive : public IDrive, public IMutable
    {
    public:
        virtual void vfunc_02();
        virtual void Destroy(int flags);    // slot 3
        void vfunc_10(int a);

        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C  the real drive
        int m_Priority;         // +0x10  the priority its requests are queued with
        int m_Outstanding;      // +0x14
        int m_LastError;        // +0x18
        int m_Field1C;          // +0x1C
        bool m_FindOpen;        // +0x20  a directory search is open
    };

}

void core::InstanceDrive::vfunc_10(int a)
{
    DriveFindNextRequest* memory = (DriveFindNextRequest*)sub_002A9880(sizeof(DriveFindNextRequest));
    DriveFindNextRequest* request = memory ? memory->sub_002AAD00(this, a) : 0;
    m_Drive->sub_002AC690((Request*)request, m_Priority, false);
}
