// 2025-09-26 Z Created
// 2025-10-02 Z Works somewhat

#include <inherit_list.h>

// Bitmask used to solve
#define ITEM_STR 0x01   // Type string
#define ITEM_ARR 0x02   // Type array
#define ITEM_ROT 0x04   // Item root
#define ITEM_FST 0x08   // Item first
#define ITEM_LST 0x10   // Item last

int iCount = 0;

// "\u2500" "─"
// "\u2514" "└"
// "\u251c" "├"
// "\u2502" "│"

void new_tree( mixed *data, int level, string PreIndent = "", string PostIndent = "" )
{
   // Data present?
  if( !data || sizeof( data ) == 0 )
    return;

   string indent = "";
   int total_items = sizeof( data );
   for( int i = 0; i < total_items; i++ )
   {
      int iFlags = 0x00;
        
      // First item at depth?
      int is_first_item = ( i == 0 );
      if( is_first_item )
         iFlags = ( iFlags | ITEM_FST );
        
      // Last item at depth?
      int is_last_item = ( i == total_items - 1 );
      if( is_last_item )
         iFlags = ( iFlags | ITEM_LST );
            
      // Next last item at depth?
      int is_next_last_item = ( ( i + 1 ) >= ( total_items - 1 ) );
        
      // Absolute first?
      int is_root_item = ( ( i == 0 ) && ( level == 0 ) );
      if( is_root_item )
         iFlags = ( iFlags | ITEM_ROT );
        
      if( pointerp( data[i] ) )
         iFlags = ( iFlags | ITEM_ARR );
        
      if( stringp( data[i] ) )
         iFlags = ( iFlags | ITEM_STR );
        
      if( iFlags & ITEM_STR ) // If string
      {
         if( iFlags & ITEM_ROT )
               write( "[" + data[i] + "]\n" );
         else
         {
            // First && Last
            if( ( iFlags & ITEM_FST ) && ( iFlags & ITEM_LST ) )
               write( PreIndent+"└──"+"[ERR" + data[i] + "]\n" );
               // First && !Last
            if( ( iFlags & ITEM_FST ) && !( iFlags & ITEM_LST ) )
            {
               if( level > 1 )
                  write( PreIndent+"[" + data[i] + "]\n" );
               else
                  write( PreIndent+"└──"+"[" + data[i] + "]\n" );
            }
            // !First && Last
            if( !( iFlags & ITEM_FST ) && ( iFlags & ITEM_LST ) ) // Last 1 indent
               write( PostIndent+"└──"+"[" + data[i] + "]\n" );
            // !First && !Last
            if( !(iFlags & ITEM_FST) && !(iFlags & ITEM_LST) ) // !Last && !First 1 indent
               write( PostIndent+"├──"+"[" + data[i] + "]\n" );
            }
        }
        else if( iFlags & ITEM_ARR ) // If array
        {
            // First && !Last
            if( (iFlags & ITEM_FST) && !(iFlags & ITEM_LST) )
                new_tree( data[i], (level+1), PreIndent+"ERR", PostIndent+"ERR" );
            // First && Last
            if( (iFlags & ITEM_FST) && (iFlags & ITEM_LST) )
                new_tree( data[i], (level+1), PreIndent+"ERR", PostIndent+"ERR" );
            // !First && Last
            if( !(iFlags & ITEM_FST) && (iFlags & ITEM_LST) )
                new_tree( data[i], (level+1), PreIndent, PostIndent+"   " ); //overhang
            // !First && !Last
            if( !(iFlags & ITEM_FST) && !(iFlags & ITEM_LST) )
                new_tree( data[i], (level+1), PostIndent+"├──", PostIndent+"│  " ); // under │  
      }
      iCount++;
   }
}

execute( str )
{
   if( !str )
   {
      write( "Usage: inherits ?|<object>\n" );
      return 1;
   }

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

   mixed *data = inherit_list( ob, INHLIST_TREE | INHLIST_TAG_VIRTUAL );
   new_tree( data, 0 );
  
   return 1;
}
