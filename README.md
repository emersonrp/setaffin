
# setaffin.exe -- a wrapper to set CPU affinity

Update: 2025 is here, and this is little utility is of -extremely- limited
use any more.  Still, it's here if you need it.  Let me know if you find
yourself using it for anything.  I've cleaned up the README, updated the
LICENSE file, and fixed a 25-year-old code typo.

Actually compiling this for its intended use-case has become a bit more of
a chore in modern times, as getting a 32-bit toolchain set up is a hassle.
I haven't yet tried to see if a 64-bit toolchain will do the right thing at
all.  I suspect it'd require at least some hacking on the Makefile.

The `setaffin.exe` binary in the repo is one I compiled in 2001 using
Cygwin / MinGW, and worked for me for many years.  YMMV.  I suspect, though,
that it'll work great for the intended use case, and might even be able to
be pressed into service as a Steam Compatibility Tool with some tinkering.
If you try that, let me know!

Enjoy!

<hr>

## Original README

Upon migrating my Windows-land from Win98 to Win2K, a bunch of my games
stopped working, ones that everyone else on the 'net seemed to have no
trouble with.  After digging around, it became pretty clear to me that
Direct3D-based games are _very_ unstable on SMP-based systems.  This is
a drag, because I've been SMP-enabled since a dual Pentium-120 years
ago.

I discovered a workaround is to launch the game, go into Task Manager,
select the process, right-click, "Set Affinity..." and turn off one or
the other of the CPU's.  Quite a pain, and [Black & White](https://en.wikipedia.org/wiki/Black_%26_White_%28video_game%29), for instance,
would invariably hit the crashing spot before I could get through that
process.

So, I decided to get my fingers dirty.

`setaffin.exe` is a tiny blob of code that sets its CPU affinity to CPU 0,
then spawns whatever is specified on the command line, which inherits this
CPU affinity.  So, to launch [Deus Ex](https://en.wikipedia.org/wiki/Deus_Ex_%28video_game%29) (a classic example of an SMP-unhappy
game):

    c:\path\to\setaffin.exe c:\Games\DeusEx\System\DeusEx.exe

...and you're off.


`setaffin` ought to do The Right Thing(tm) if you need to feed your program
extra options, just tack them on the end.  And theoretically, spaces in
filenames aren't going to bug it either, but if you have any trouble, you
might try something like:

    c:\path\to\setaffin.exe "c:\program files\other directory\game.exe"

with the "" to make your intent clear.

Once you have your command all hacked together the way you want it, I'd
recommend sticking it into a .BAT file.


`setaffin` is the first programming I've ever done to the Win32 API (and some
of the first C I've ever thrown together from scratch), so feel free to send
comments and bug reports and criticisms and money and the like.

I compile the program using the gcc in the Cygwin package, but it's SO simple
and small that it could probably be dropped into any compiler and made to
work.

As mentioned in the file [LICENSE](LICENSE), this is released under the Gnu
Public License, version 2 or later.  Short form:  "Do whatever you want with
this code, but any changes you release also must be released under the GPL.
No warranty -- if it sets your system on fire, roast hotdogs, but don't
complain."  Check [LICENSE](LICENSE) for exact legalese of all that.

All feedback to [emerson@hayseed.net](mailto:emerson@hayseed.net).  Thanks!

