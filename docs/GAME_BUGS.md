# Bugs in the original game

Bugs that are in the game as it shipped, found by people who traced them. Each says which build it was
seen in, what goes wrong, where in the code, and how sure the finding is. The functions are leads for
this project: knowing what a function gets wrong says a lot about what it is for.

## The loading screen after the opening credits drive can stay up for good

**Seen in:** a static recompilation of the PC game 1.00.2 to ARM64, which runs the game's own code.
The same behaviour was shown in the original PC code, run instruction by instruction in an emulator,
so it is not something the recompilation added. Whether it shows on a real PC depends on timing.
**Source:** a bug report of 21 November 2026 from that recompilation, shared with this project.

**What goes wrong.** The game streams the city in through a context with three slots. When the camera
changes what it can see, the streaming code applies the old selection and then the new one. A package
that is retiring at that moment (state 0x100) is skipped by the old-only branch of the function that
applies a selection (PC 0x4B8850, Xbox 0x93C70): its selection mark is cleared, but a request the camera
had queued for it earlier stays in the retry queue. On the next pump the queue replays that request
(PC 0x4B5BD0, Xbox 0x90F40), and the package (Trailer Park, in the traced run) loads again and takes a
slot nothing needs. With the other two slots held by packages that are ready, the Drive-In package finds
no free slot (PC 0x4B7F70, Xbox 0x93590) and never starts loading. The credits director waits for it, so
the teleport to the Secretary scene is never asked for and the loading screen stays. In the traced run
the Drive-In asked 3,813 times over 64 seconds.

**It is in the Xbox game too.** The Xbox function (0x93C70) has the same branch, instruction for
instruction apart from addresses: an old member (mark 2) is released only when its state passes the same
mask, 0x6FE (read from 0x3A42E0 on Xbox, 0x73BD10 on PC), and its mark is cleared either way. So the
behaviour is in the game's source, not added by the PC port. Whether it ever shows on a console depends
on timing that has not been measured.

**The recompilation's fix** erases only that stale request, through the game's own erase (PC 0x4B4F40)
and free, when the camera's old-only selection withdraws a package whose queued request came from the
camera alone and nothing else depends on it. It passed 115 offline checks and two live runs. The report
lists what is still unexplained: an earlier failure that stopped at a later point, missing building
sections during the drive, and stutters.

**Functions:** `reports/recomp_leads_xb.json` has thirteen of them with their Xbox twins and what each
does; `python portal/agent.py packet` prints that as a `lead:` line.
