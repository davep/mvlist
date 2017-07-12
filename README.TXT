A couple of times in the last month or so the question as to how you can get
a list of PUBLIC and PRIVATE variables, at run-time, has been asked in
comp.lang.clipper.

Included here are a couple of functions that will allow you to do this.  Note
that because they use the internals of Clipper (in this case, some of the
debugger support functions) the code may break depending on your version of
Clipper.

The functions are:

        mvlPublics()  --> aPublics
        mvlPrivates() --> aPrivates
        mvlCntPub()   --> nPublics
        mvlCntPri()   --> nPrivates

Many thanks must go to Ian 'DrDebug' Day who pointed me in the direction of
which internals I needed to work with.

PLEASE NOTE: THIS CODE IS DISTRIBUTED IN THE HOPE THAT IT WILL BE USEFUL,
BUT WITHOUT ANY WARRANTY; WITHOUT EVEN THE IMPLIED WARRANTY OF
MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.

In other words, if it breaks something, don't complain to me.

davep@hagbard.demon.co.uk (Dave Pearson)
http://www.acemake.com/hagbard/
http://www.hagbard.demon.co.uk/
