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
  char direction; 
  char key; 
  KeySet keyset; 
 
  // Constructor 
  public CalculatorCommand( KeySet keyset, 
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
 
  public int Key 
  { 
    set{ key = value; } 
  } 
 
  // Methods 
  override public void Execute() 
  { 
    keyset.Set( direction, key ); 
  } 
   

// "Receiver" 
class Calculator 
{ 
  // Fields 
  private int total = 0; 
 
  // Methods 
  public void Operation( char @operator, int operand ) 
  { 
    switch( @operator ) 
    { 
      case '+': total += operand; break; 
      case '-': total -= operand; break; 
      case '*': total *= operand; break; 
      case '/': total /= operand; break; 
    } 
    Console.WriteLine( "Total = {0} (following {1} {2})", 
      total, @operator, operand ); 
  } 
} 
 
// "Invoker" 
class User 
{ 
  // Fields 
  private Calculator calculator = new Calculator(); 
  private ArrayList commands = new ArrayList(); 
  private int current = 0; 
 
  // Methods 
  public void Redo( int levels ) 
  { 
    Console.WriteLine( "---- Redo {0} levels ", levels ); 
    // Perform redo operations 
    for( int i = 0; i < levels; i++ ) 
      if( current < commands.Count - 1 ) 
        ((Command)commands[ current++ ]).Execute(); 
  } 
 
  public void Undo( int levels ) 
  { 
    Console.WriteLine( "---- Undo {0} levels ", levels ); 
    // Perform undo operations 
    for( int i = 0; i < levels; i++ ) 
      if( current > 0 ) 
        ((Command)commands[ --current ]).UnExecute(); 
  } 
 
  public void Compute( char @operator, int operand ) 
  { 
    // Create command operation and execute it 
    Command command = new CalculatorCommand( 
      calculator, @operator, operand ); 
    command.Execute(); 
 
    // Add command to undo list 
    commands.Add( command ); 
    current++; 
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
    user.Compute( '-', 50 ); 
    user.Compute( '*', 10 ); 
    user.Compute( '/', 2 ); 
 
    // Undo and then redo some commands 
    user.Undo( 4 ); 
    user.Redo( 3 ); 
  } 
} 