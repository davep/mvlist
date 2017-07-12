#include "box.ch"

// Just a little test. You get bonus points if you know the quotes. :-)

Function Main()

   Public One, Of, Those, Days, In, England
   Private Soilent, Green, Is, People

   LookAt( mvlPublics(),  "Public" )
   LookAt( mvlPrivates(), "Private" )

   SubLevel1()

Return( NIL )

Static Function LookAt( a, cType )

   Cls
   devpos( 0, 0 ) ; devout( "List of " + cType + " variables visible in " + procname( 1 ) )

   dispbox( 2, 10, maxrow() - 1, 22, B_SINGLE + " " )

   achoice( 3, 11, maxrow() - 2, 21, a )

Return( NIL )

Static Function SubLevel1()

   Private So, Long, And, Thanks, For, All, The, Fish

   LookAt( mvlPrivates(), "Private" )

   SubLevel2()

Return( NIL )

Static Function SubLevel2()

   Private Sooner, Or, Later, It, Was, Bound, To, Happen

   LookAt( mvlPrivates(), "Private" )

   SubLevel3()

Return( NIL )

Static Function SubLevel3()

   Private Few, Men, Even, Considered, The, Possibility, Of, Life, On, Mars

   LookAt( mvlPrivates(), "Private" )

Return( NIL )
