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
  public KeyboardCommand( KeySet keyset, string direction, string key ) 
  { 
    this.keyset = keyset; 
    this.direction = direction; 
    this.key = key; 
  } 
 
  // Properties 
  public string Direction  
  { 
    set{ direction = value; } 
  } 
 
  public string Key 
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
  public void Set( string key, string direction ) ; 
} 
 
// "Invoker" 
class User 
{ 
  // Fields 
  private Keyset keyset = new Keyset(); 
  // Methods 
  public void Setting( string direction, string key );
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
 
<<<<<<< HEAD
    user.Compute( '+', 100 );  
=======
    user.Compute( '+', 100 ); 
    user.Compute( '-', 50 ); 
    user.Compute( '*', 10 ); 
    user.Compute( '/', 2 ); 
 
    // Undo and then redo some commands 
    user.Undo( 4 ); 
    user.Redo( 3 ); 
>>>>>>> origin/fredhua
  } 
} 
#endif /* defined(__TileGame__COMMAND__) */