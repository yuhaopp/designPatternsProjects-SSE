#ifndef __COMMAND_H__
#define __COMMAND_H__


#include "cocos2d.h"
USING_NS_CC;


// "Command" 
abstract class Command 
{ 
  // Methods 
  abstract public void Execute(); 
} 
 
// "ConcreteCommand" 
class KeyboardCommand : Command 
{ 
  // Fields 
  string direction; 
  string key; 
  KeySet keyset; 
 
  // Constructor 
  public SettingCommand( KeySet keyset, 
    char direction, char key ) 
  { 
    this.keyset = keyset; 
    this.direction = direction; 
    this.key = key; 
  } 
 
  // Properties 
  public char Direction  
  { 
    set{ direction = value; } 
  } 
 
  public char Key 
  { 
    set{ key = value; } 
  } 
 
  // Methods 
  override public void Execute() 
  { 
    keyset.Set( direction, key ); 
  } 
   

// "Receiver" 
class KeySet 
{ 
 
  // Methods 
  public void Set( char key, char direction ) 
  { 
    switch( direction ) 
    { 
      case 'up': ^^^^; break; 
      case 'down': ^^^^; break; 
      case 'left': ^^^^; break; 
      case 'right': ^^^^; break; 
    }
  } 
} 
 
// "Invoker" 
class User 
{ 
  // Fields 
  private Keyset keyset = new Keyset(); 
 
  // Methods 
 
  public void Setting( string direction, string key ) 
  { 
    // Create command operation and execute it 
    public SettingCommand(keyset, direction, key );
    command.Execute(); 
  } 
} 
 
/// <summary> 
/// CommandApp test 
/// </summary> 
public class Client 
{ 
  public static void Main( string[] args ) 
  { 
    // Create user and let her compute 
    User user = new User(); 
 
    user.Compute( '+', 100 );  
  } 
} 