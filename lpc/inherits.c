// 2025-09-26 Created

// TODO
// brain not working
// * Use ? for list of local valid id's
// * INHLIST_FLAT(0) | INHLIST_TREE(1) | INHLIST_TAG_VIRTUAL(2)

/* INHLIST_TREE
   The result is an array starting the with the filename of ob itself, followed
   by the all directly inherited objects. If one of the inherited objects has no
   inherits by itself, then its name will be stored directly in the array.
   If one inherited object has inherits by itself, a subvector will be created
   and stored in the result vector. The subvector(s) have the same structure as
   the main result vector.

   INHLIST_TAG_VIRTUAL
   All names in the result are prefixed with a tag: ” ” (two spaces) for
   normal inherits, “v ” for virtual inherits.
*/

/* Display modes

// "\u2500" "─"
// "\u2514" "└"
// "\u251c" "├"
// "\u2502" "│"

Box drawing         Simple

[Item 1]            [Item 1]
└──[Item 2]         +---[Item 2]
   ├──[Item 3]          +---[Item 3]
   │  └──[Item 4]       |   +--[Item 4]
   │     ├──[Item 5]    |      +---[Item 5]
   │     └──[Item 6]    |      +---[Item 6]
   └──[Item 7]          +---[Item 7]
*/

#include <inherit_list.h>

// Fixme
void print_indent( )
{
}

/*
  case:direct_inherit ({"0.0",({"1.0","1.1","1.2","1.3"}) })
  [0.0]
  ├──[1.0]
  ├──[1.1]
  ├──[1.2]
  └──[1.3]
*/

// Fixme
void print_tree( mixed *data, int depth )
{
   // Data present?
  if( !data || sizeof( data ) == 0 )
    return;

   // Total number of items at current depth
   int total_items = sizeof( data );

   // Fixme
   for( int i = 0; i < total_items; i++ )
   {
      if( stringp( data[i] ) )
      {
         // Is item
      }
      else if( pointerp( data[i] ) )
      {
         // Is array, recursion
         print_tree( data[i], depth + 1 );
      }
      else
      {
         // Should not be here
      }
   }
}

execute( str )
{
  // No arg?
  if( !str )
  {
    write( "Usage: inherits ?|<object>\n" );
    return 1;
  }

  // Check if object is present?
  object *obs;
  object ob;
  obs = all_inventory( environment( this_player() ) );
  for( int i = 0; i < sizeof( obs ); i++ )
  {
    if( obs[i]->query_id() == str )
      ob = obs[i];
  }

  // Object not found.
  if( !ob )
  {
    write( "Object \"" + str + "\" not found.\n" );
    return 1;
  }

  // Get inherits of object
  mixed *data = inherit_list( ob, INHLIST_TREE | INHLIST_TAG_VIRTUAL );

  print_tree( data, 0 );
  
  return 1;
}
