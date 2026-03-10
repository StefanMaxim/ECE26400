// ***
// *** You MUST modify this file
// ***

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// do NOT modify this function
static void printDeck(CardDeck deck)
{
  int ind;
  for (ind = 0; ind < deck.size; ind++)
  {
    printf("%c ", deck.cards[ind]);
  }
  printf("\n");
}

#ifdef TEST_DIVIDE
// leftDeck and rightDeck are arrays of CardDeck
// This function creates pairs of left and right decks
// Each pair divides the original deck into two non-overlapping decks and
// together they form the original deck.
//
// You can think of the left deck held by the left hand taking some
// cards (at least one) from the top of the original deck.
//
// The right deck is held by the right hand taking some (at least one)
// cards from the bottom of the original deck.
void divide(CardDeck origDeck, CardDeck *leftDeck, CardDeck *rightDeck)
{
  int k;
  int n = origDeck.size;

  for (k = 1; k <= n - 1; k++)
  {
    leftDeck[k - 1].size = k;
    memcpy(leftDeck[k - 1].cards, origDeck.cards, (size_t)k);

    rightDeck[k - 1].size = n - k;
    memcpy(rightDeck[k - 1].cards, origDeck.cards + k, (size_t)(n - k));
  }
}
#endif

#ifdef TEST_INTERLEAVE

// Interleave two decks to generate all possible results.
//
// If the leftDeck is {'A'} and the right deck is {'2', '3'}, this
// function prints
// A 2 3
// 2 A 3
// 2 3 A
//
// If the leftDeck is {'A', '2'} and the right deck is {'3', '4'}, this
// function prints
// 3 4 A 2
// 3 A 4 2
// A 3 4 2
// 3 A 2 4
// A 3 2 4
// A 2 3 4
//
// Please notice the space does not matter because grading will use
// diff -w
//
// How to generate all possible interleaves?

// Understand that a card at a particular position can come from
// either left or right (two options). The following uses left for
// explanation but it is equally applicable to the right.
//
// After taking one card from the left deck, the left deck has one
// fewer card. Now, the problem is the same as the earlier problem
// (thus, this problem can be solved by using recursion), excecpt one
// left card has been taken. Again, the next card can come from left
// or right.
//
// This process continues until either the left deck or the right deck
// runs out of cards. The remaining cards are added to the result.
//
// It is very likely that you want to create a "helper" function that
// can keep track of some more arguments.  If you create a helper
// function, please keep it inside #ifdef TEST_INTERLEAVE and #endif
// so that the function can be removed for grading other parts of the
// program.

static void interleaveHelper(CardDeck leftDeck, CardDeck rightDeck, CardDeck *result, int li, int ri, int pos)
{
  if (li == leftDeck.size)
  {
    while (ri < rightDeck.size)
    {
      result->cards[pos++] = rightDeck.cards[ri++];
    }
    printDeck(*result);
    return;
  }

  if (ri == rightDeck.size)
  {
    while (li < leftDeck.size)
    {
      result->cards[pos++] = leftDeck.cards[li++];
    }
    printDeck(*result);
    return;
  }

  result->cards[pos] = rightDeck.cards[ri];
  interleaveHelper(leftDeck, rightDeck, result, li, ri + 1, pos + 1);

  result->cards[pos] = leftDeck.cards[li];
  interleaveHelper(leftDeck, rightDeck, result, li + 1, ri, pos + 1);
}
void interleave(CardDeck leftDeck, CardDeck rightDeck)
{
  CardDeck result;
  result.size = leftDeck.size + rightDeck.size;

  interleaveHelper(leftDeck, rightDeck, &result, 0, 0, 0);
}
#endif

#ifdef TEST_SHUFFLE
// The shuffle function has the following steps:

// 1. calculate the number of possible left and right decks. It is
// the number of cards - 1 because the left deck may have 1, 2,...,
// #cards - 1 cards.
//
// 2. allocate memory to store these possible pairs of left and right
// decks.
//
// 3. send each pair to the interleave function
//
// 4. release allocated memory
//
void shuffle(CardDeck origDeck)
{
  int n = origDeck.size;
  int numPairs = n - 1;

  CardDeck *leftDeck = (CardDeck *)malloc(sizeof(CardDeck) * (size_t)numPairs);
  CardDeck *rightDeck = (CardDeck *)malloc(sizeof(CardDeck) * (size_t)numPairs);

  if (leftDeck == NULL || rightDeck == NULL)
  {
    free(leftDeck);
    free(rightDeck);
    return;
  }

  divide(origDeck, leftDeck, rightDeck);

  for (int i = 0; i < numPairs; i++)
  {
    interleave(leftDeck[i], rightDeck[i]);
  }

  free(leftDeck);
  free(rightDeck);
}
#endif
