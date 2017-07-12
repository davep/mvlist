#include <extend.api>
#include <item.api>
#include <fm.api>

/* Constants for variable type in _dbgVarInfo() */

#define V_PRIVATE 0x08
#define V_PUBLIC  0x10

/* Holds details about a variable. */

typedef struct
{
    unsigned uType;
    char     *pszVarName;
    char     *pszVarValue;
} DBGVARINFO, *PDBGVARINFO;

/* Internal debugger support functions. */

int         _dbgActCount( void );        /* Activation level. */
PDBGVARINFO _dbgVarInfo( int, int, unsigned * ); /* Variable information. */

/* Local support functions. */

static unsigned _mvlCountPrivates( void );
    
/* Publics are dead easy, they are visible everywhere and so we can
 * do them in one go (activation level 0).
 */

CLIPPER mvlPublics( void )
{
    unsigned    uVariables;
    PDBGVARINFO pVarInfo = _dbgVarInfo( 0, V_PUBLIC, &uVariables );
    ITEM        aVars    = _itemArrayNew( uVariables );
    ITEM        cName    = _itemNew( NULL );
    unsigned    u;

    for ( u = 0; u < uVariables; u++ )
    {
        cName = _itemPutC( cName, pVarInfo[ u ].pszVarName );
        aVars = _itemArrayPut( aVars, u + 1, cName );
    }

    _itemRelease( cName );
    _itemRelease( _itemReturn( aVars ) );
    
    _xfree( pVarInfo );
}

/*
 */

CLIPPER mvlCntPub( void )
{
    unsigned    uVariables;
    PDBGVARINFO pVarInfo = _dbgVarInfo( 0, V_PUBLIC, &uVariables );

    _xfree( pVarInfo );
    _retnl( uVariables );
}

/* PRIVATEs are a bit of a pain. The _dbfVarInfo() function returns the
 * PRIVATEs that were "created" at the given activation level. So, to
 * get a list of all PRIVATEs that are *visible* at the current
 * activation level, we have to loop our way back up the stack.
 */

CLIPPER mvlPrivate/*s*/( void )
{
    ITEM     aVars    = _itemArrayNew( _mvlCountPrivates() );
    ITEM     cName    = _itemNew( NULL );
    unsigned uActLvl  = _dbgActCount();
    unsigned uPrivate = 1;

    do
    {
        unsigned    uVariables;
        PDBGVARINFO pVarInfo = _dbgVarInfo( uActLvl, V_PRIVATE, &uVariables );
        unsigned    u;

        for ( u = 0; u < uVariables; u++ )
        {
            cName = _itemPutC( cName, pVarInfo[ u ].pszVarName );
            aVars = _itemArrayPut( aVars, uPrivate++, cName );
        }

        _xfree( pVarInfo );
    } while ( --uActLvl );
    
    _itemRelease( cName );
    _itemRelease( _itemReturn( aVars ) );
}

/*
 */

CLIPPER mvlCntPri( void )
{
    _retnl( _mvlCountPrivates() );
}

/*
 */

static unsigned _mvlCountPrivates( void )
{
    unsigned uActLvl = _dbgActCount();
    unsigned uCount  = 0;

    do
    {
        unsigned    uPrivates;
        PDBGVARINFO pVarInfo = _dbgVarInfo( uActLvl, V_PRIVATE, &uPrivates );

        uCount += uPrivates;
        _xfree( pVarInfo );
    } while ( --uActLvl );

    return( uCount );
}
