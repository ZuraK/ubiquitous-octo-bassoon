// 2025-09-26 Created

// TODO
// * Use ? for list of local valid id's
// * INHLIST_FLAT | INHLIST_TREE | INHLIST_TAG_VIRTUAL

/* Display modes
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

// Fixme
void print_tree( mixed *data, int level )
{
  if( !data || sizeof( data ) == 0 )
    return;
}

execute( str )
{
  // No arg?
  if( !str )
  {
    write( "Usage: inherits ?|<object>\n" );
    return 1;
  }

  // Check if target is present?
  object *obs;
  object ob;
  obs = all_inventory( environment( this_player() ) );
  for( int i = 0; i < sizeof( obs ); i++ )
  {
    if( obs[i]->query_id() == str )
      ob = obs[i];
  }

  if( !ob )
  {
    write( "Object \"" + str + "\" not found.\n" );
    return 1;
  }

  // Get inherits
  mixed *data = inherit_list( ob, INHLIST_TREE | INHLIST_TAG_VIRTUAL );

  print_tree( data, 0 );
  
  return 1;
}
