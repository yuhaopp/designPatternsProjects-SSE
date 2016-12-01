#include "Command.h"

void KeySet::Set( string key, string direction ) 
{ 
    switch( direction ) 
    { 
      case 'up': ^^^^; break; 
      case 'down': ^^^^; break; 
      case 'left': ^^^^; break; 
      case 'right': ^^^^; break; 
    }  
} 

void User::Setting( string direction, string key ) 
{ 
    // Create command operation and execute it 
   Command command = new KeyboardCommand( KeySet keyset, string direction, string key );
   command.Execute(); 
}