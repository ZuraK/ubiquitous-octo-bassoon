/* Pseudo/Braindump/Sketching : Strings & ANSI
 * V 1
 * 2025-09-22 (zurak)
 * 
*/

// ESC "\u001b"
// [ "\u005b"
#define T_RESET     "[0m"  // Reset
#define T_RED       "[91m" // FG red
#define T_GREEN     "[92m" // FG green
#define T_YELLOW    "[93m" // FG yelow
#define T_CYAN      "[96m" // FG cyan
// 38;5;<n>m;
// 38;2;<r>;<g>;<b>m


// Decorate
#define WRAP( x, y )  ( ( ( y ) + ( x ) + (T_RESET) ) )
// C: WRAP( "ABC  ", T_RED ) -> "[91mABC  [0m"


// Fixme:
// Currently if multiple codes is supplied, they will stack as following:
// "[1m[2m[3m[4m[5m[6m"
//   1  2  3  4  5  6
// Full function would allow parameters and would look result as:
// "[1;2;3;4;5;6m"
//   1
// OR
// "[1;2m[3;4m[5;6m"
//   1    2    3


/**
  * Check if <string> str contains ANSI escape codes.
  * Returns <int> 0 if false, 1 if true.
  * @param str String to test.
  */
int containsANSI( string str )
{
  return result;
}

/**
  * Check if <string> str contains ANSI escape codes specified in <list> lst.
  * Returns <int> 0 if false, 1 if true.
  * @param str String to test.
  * @param lst List of ANSI codes to check for.
  */
int containsANSI( string str, list lst )
{
  return result;
}

// ANSI code counting
// Count number of codes
// Count number of codes matching specified list of codes
// Count number of start codes
// Count number of stop codes
// Count number of misc codes

// F: MAP ANSI in _str_
// R: MAP[]

// F: _str_ size_wansi
// R: <int>
// Get size with ANSI, similar to sizeof(str)/strlen(str)

// F: _str_ size_oansi
// R: <int>
// Size only ANSI, sizeANSI(str)

// F: _str_ size_iansi
// R: <int>
// Get size ignore ANSI, sizeof(str) - sizeANSI(str)

// str="abc def ghi"

// F: wrap_a( _str_, code_beg, code_end )
// wrap_a( str, X, Y ) --> str="Xabc def ghiY"

// F: wrap_b( _str_, code, flag = 0 )
// wrap_b( str, X ) --> str="XAabc def ghiXB"

// "abc def ghi"
// "<0>abc<1> <2>def<3> <4>ghi<5>"
// word,0 = abc
// word,1 = def
// word,2 = ghi
// word_beg,1 = _def   start of word 1
// word_end,2 = ghi_   end of word 2
// string_beg          start of string
// string_end          end of string

// F: wrap_c( _str_, X, 2 )
// wrap_b( str, X, 2 ) --> str="abc XAdef ghiXB"

// F: wrap_c( _str_, X, 2, 3 )
// wrap_b( str, X, 2 ) --> str="abc XAdefXB ghi"



// F: strip all ansi from _str_
// F: strip LST ansi from _str_
// F: strip *predefined* ansi from _str_
// ## Predefined Default group|s
// ## Custom, any combination: Range|s, List, Range|s + List

// F: Reverse _str_ try to preserve matching ANSI locations without breaking escape codes

