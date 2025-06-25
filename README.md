
# setaffin.exe -- a wrapper to set CPU affinity.


Upon migrating my Windows-land from Win98 to Win2K, a bunch of my games
stopped working, ones that everyone else on the 'net seemed to have no
trouble with.  After digging around, it became pretty clear to me that
Direct3D-based games are _very_ unstable on SMP-based systems.  This is
a drag, because I've been SMP-enabled since a dual Pentium-120 years
ago.

I discovered a workaround is to launch the game, go into Task Manager,
select the process, right-click, "Set Affinity..." and turn off one or
the other of the CPU's.  Quite a pain, and Black&White, for instance,
would invariably hit the crashing spot before I could get through that
process.

So, I decided to get my fingers dirty.

`setaffin.exe` is a tiny blob of code that sets its CPU affinity to CPU 0,
then spawns whatever is specified on the command line, which inherits this
CPU affinity.  So, to launch Deus Ex (a classic example of an SMP-unhappy
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

