# SPEC-020: the request base classes

**Examiner:** Claude (AI assistant) for RRutherrfordd, 2026-11-27.
**Outside material read:** leaked source, read directly: the request header and the definition order of the
request source file of the 2003 *Simpsons: Hit & Run* core library. Facts below are from `default.xbe`.
**Status:** class card; nothing compiled; no second reviewer.

| Class (RTTI) | Table | Size of its own part | Members |
| :--- | :--- | :--- | :--- |
| `core::Request` | 0x3DA6C8 (7 slots) | 8 | +4 next request |
| `core::FileRequest` | 0x3DA750 | 0xC | +8 `core::File*` |
| `core::DriveRequest` | 0x3DA790 | 0xC | +8 `core::InstanceDrive*` |
| `core::CompletionCallbackRequest` | 0x3DA7B0 (8 slots) | 0xC | +8 the registering thread |
| `core::CompletionEventRequest` | 0x3DA6E8 | 0x10 | +8 semaphore, +0xC `core::Drive*` (constructor calls its slot 0) |
| `core::FileCompletionRequest` | 0x3DA708 | 0x18 | +0xC file, +0x10 callback object, +0x14 user data |

Slots of `core::Request`: 0 destructor with delete flag; 1 do the work; 2 (key) should cancel; 3 owning
drive; 4 prepare again after an error; 5, 6 the two values SPEC-017 section 2 reads. Slot 7 of the
callback level is the callback itself. Slots 1 and 4 return the status the worker switches on
(SPEC-018 B.4.11): 0 error, 1 done, 2 more to do (re-queued at the head), anything else left alone.

**Shapes.**

* Base constructor, always expanded: table 0x3DA6C8; +4 = 0; call 0x250EB0.
* Every constructor level ends with its own call to 0x250EB0 (result unused), after its member stores.
* `core::FileRequest`'s constructor is 0x2AA810, **called** by every file request's constructor (one
  argument: the file). `core::DriveRequest`'s is 0x2AAB70, called the same way.
* `core::FileRequest`'s destructor (0x2AAAB0, deleting form): table 0x3DA750; lock the file (slot 0 of the
  file's +4 part); file's +0x18 −= 1; unlock; file's slot 1 (drop a reference); then the base level.
  `core::DriveRequest`'s (0x2AAD90) is the same on the instance drive with the count at +0x14. So
  File +0x18 and InstanceDrive +0x14 are "requests outstanding".
* `core::FileCompletionRequest`'s constructor (0x2AA650; (thread, file, callback, user data)): three table
  stores (0x3DA6C8, 0x3DA7B0, 0x3DA708) with the base levels expanded; callback's slot 0; lock the file;
  file's +0x18 += 1; unlock; file's slot 0. In that order.
* 0x2AA8D0 (`core::FileOpenByKeyRequest` destructor): +0x10 object's slot 1 first, then the
  `core::FileRequest` destructor's statements expanded, then table 0x3DA6C8.
