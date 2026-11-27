// bin: xb
// va: 0x002AACB0
// what: Constructs a find-first request: the drive-request base, the search's argument and a copy of the name, cut to 256 characters.
// tool: Claude (from SPEC-020)

extern "C" char DAT_003DA6C8[];     // core::Request's table
extern "C" char DAT_003DA750[];     // core::FileRequest's
extern "C" char DAT_003DA790[];     // core::DriveRequest's
extern "C" char DAT_003DA7B0[];     // core::CompletionCallbackRequest's
extern "C" char DAT_003DA708[];     // core::FileCompletionRequest's
extern "C" char DAT_003DA72C[];     // core::DriveCompletionRequest's
extern "C" char DAT_003DA770[];     // core::FileOpenByKeyRequest's
extern "C" char DAT_003DA9B4[];     // core::DriveFindFirstRequest's
extern "C" char DAT_004BDD44[];     // the lock around the request allocator

const char* __cdecl sub_00250EB0();             // the library's name ("core"); every constructor level calls it
void __cdecl sub_00283B80(void* lock);          // take a lock
void __cdecl sub_00283B70(void* lock);          // let it go
extern "C" char* __cdecl strncpy(char* to, const char* from, unsigned int count);

// The allocator requests come from.
class Allocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(void* memory);    // give memory back
};
extern "C" Allocator* DAT_004BDD60;

namespace core
{
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The two owners a request counts itself on (SPEC-019): only what the requests use.
    class File : public IRefCount, public IMutable
    {
    public:
        int m_RefCount;         // +0x08
        void* m_Drive;          // +0x0C
        int m_Priority;         // +0x10
        int m_LastError;        // +0x14
        int m_Outstanding;      // +0x18
    };

    class InstanceDrive : public IRefCount, public IMutable
    {
    public:
        int m_RefCount;         // +0x08
        void* m_Drive;          // +0x0C
        int m_Priority;         // +0x10
        int m_Outstanding;      // +0x14
    };

    // What a completion request calls back; counted like the owners.
    class Callback : public IRefCount
    {
    };

    // A request with its table written as a member: these are its constructors and destructors.
    class DriveFindFirstRequest
    {
    public:
        DriveFindFirstRequest* sub_002AACB0(InstanceDrive* drive, const char* name, int what);
        void sub_002AAB70(InstanceDrive* drive);
        void* m_Table;          // +0x00
        void* m_Next;           // +0x04
        InstanceDrive* m_Owner; // +0x08
        char m_Name[0x101];     // +0x0C
        int m_What;             // +0x110
    };
}

core::DriveFindFirstRequest* core::DriveFindFirstRequest::sub_002AACB0(InstanceDrive* drive, const char* name, int what)
{
    sub_002AAB70(drive);
    m_Table = DAT_003DA9B4;
    m_What = what;
    sub_00250EB0();
    strncpy(m_Name, name, 0x100);
    m_Name[0x100] = 0;
    return this;
}
