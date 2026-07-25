#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "assert.h"
#include "list.h"
#include <iostream>

/** COPIED FROM LIST.H FOR REFERENCE
 *
 * struct node{
 *  int val;
 *  struct node* next;
 *};
 */

/** remove_matches:
 * removes all list entries that match the supplied value
 * for example calling remove_matches on a list with {1, 3, 3, 4, 2, 5}
 * and a value of 3 should yield { 1, 4, 2, 5 }.
 *
 * remove_matches should have a void return type
 *
 * note that when an element is added to a list, the node to store it is created
 * on the heap
 *
 * once you've implemented remove_matches, insert a call to
 * your function in the proper place
 **/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "assert.h"
#include <iostream>
#include "list.h"

using namespace std;



/** COPIED FROM LIST.H FOR REFERENCE
 *
 * struct node{
 *  int val;
 *  struct node* next;
 *};
 */

/** remove_matches:
 * removes all list entries that match the supplied value
 * for example calling remove_matches on a list with {1, 3, 3, 4, 2, 5}
 * and a value of 3 should yield { 1, 4, 2, 5 }.
 *
 * remove_matches should have a void return type
 *
 * note that when an element is added to a list, the node to store it is created
 * on the heap
 *
 * once you've implemented remove_matches, insert a call to
 * your function in the proper place
 **/

void removeMatches( node * list, int valToRemove ) {

    if (list == nullptr) {
        return;
    }
    while( list && list->val == valToRemove) {
        node *temp  = list;
        list = list->next;
        free(temp);
    }
    if ( list == nullptr ) {
        return;
    }
    node *prev = list;
    node *curr = prev->next;

    while( curr != nullptr ) {
        if (curr->val == valToRemove) {
          node *temp  = curr;
          prev->next = curr->next;
          curr = curr->next;
          free(temp);
        } else {
          prev = curr;
          curr = curr->next;
        }

    }
}
int main( int argc, char* argv[] ){
  int listVals[] = { 1, 1, 2, 3, 3, 4, 1, 3, 5, 5, 5 };
  const char* correctAnswers[] = {  
                              "1->1->2->3->3->4->1->3->5->5->5",   // 0
                              "2->3->3->4->3->5->5->5",            // 1
                              "1->1->3->3->4->1->3->5->5->5",      // 2
                              "1->1->2->4->1->5->5->5",            // 3
                              "1->1->2->3->3->1->3->5->5->5",      // 4
                              "1->1->2->3->3->4->1->3"             // 5
                              };

  int listValsLen = 11;
  char buf[128];

  for( int valToRemove = 0; valToRemove < 6; valToRemove++ ) {
    memset( buf, 0, 128 );

    struct node* list = NULL;
    for( int i = 0; i < listValsLen; i++ ) {
      listAppend( &list, listVals[ i ] );
    }

    removeMatches( list, valToRemove);

    listSprint( list, buf );
    assert( !strcmp( buf, correctAnswers[ valToRemove ] ) );
  }

  printf( "remove_matches implemented successfully\n" );
  return 0;
}
