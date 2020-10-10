#include <iostream>

using namespace std;

#include "DeckOfCards.h"
#include "Queue.h"
#include "LinkedList.h"
#include "Card.h"
#include <string>
#include <sstream>
#include <stdlib.h>

DeckOfCards::DeckOfCards()
{
    addSuit("H");
    addSuit("C");
    addSuit("S");
    addSuit("D");
}

DeckOfCards::DeckOfCards(bool shuffle)
{
}

DeckOfCards::DeckOfCards(bool shuffle, DeckOfCards& partialDeck)
{
    Card tempCard;
    int size = partialDeck.getSize();
    for (int i = 0; i < size; i++)
    {
        tempCard = partialDeck.draw();
        addCard(tempCard);
    }
}

DeckOfCards::~DeckOfCards()
{

}

void DeckOfCards::shuffle()
{
    Queue<DeckOfCards> queueOfDecks = Queue<DeckOfCards>();
    DeckOfCards *tempDeck1 = new DeckOfCards(true);
    DeckOfCards *tempDeck2 = new DeckOfCards(true);
    DeckOfCards *tempDeck3 = new DeckOfCards(true);
    DeckOfCards *tempDeck4 = new DeckOfCards(true);
    Card tempCard;
    for (int i = 0; i < 13; i++)
    {
        tempCard = draw();
        tempDeck1->addCard(tempCard);
        tempCard = draw();
        tempDeck2->addCard(tempCard);
        tempCard = draw();
        tempDeck3->addCard(tempCard);
        tempCard = draw();
        tempDeck4->addCard(tempCard);
    }
    queueOfDecks.enqueue(tempDeck1);
    queueOfDecks.enqueue(tempDeck2);
    queueOfDecks.enqueue(tempDeck3);
    queueOfDecks.enqueue(tempDeck4);
//-----------------------
    int rand(void);
    DeckOfCards tempDeck = DeckOfCards(true);
    DeckOfCards* tempDeckPtr;
    for (int i = 0; i < 1000; i++)
    {
        for (int i = 0; i <= rand() % 4; i++)
        {
            tempDeck = queueOfDecks.dequeue();
            tempDeckPtr = new DeckOfCards(true, tempDeck);
            queueOfDecks.enqueue(tempDeckPtr);
        }

        tempCard = queueOfDecks.front()->draw();

        if (tempCard.getValue() == -1)
        {
            continue;
        }

        for (int i = 0; i < rand() % 4; i++)
        {
            tempDeck = queueOfDecks.dequeue();
            tempDeckPtr = new DeckOfCards(true, tempDeck);
            queueOfDecks.enqueue(tempDeckPtr);
        }

        tempDeck = queueOfDecks.dequeue();
        tempDeck.addCard(tempCard);
        tempDeckPtr = new DeckOfCards(true, tempDeck);
        queueOfDecks.enqueue(tempDeckPtr);
    }

//------------------------
    for (int i = 0; i < 4; i++)
    {
        tempDeck = queueOfDecks.dequeue();
        for (int j = 0; j < 13; j++)
        {
            tempCard = tempDeck.draw();
            addCard(tempCard);
        }
    }


}
/*
DeckOfCards *DeckOfCards::getPartialDeck()
{
    cout << "SIZE OF QUEUE " << deck.getSize() << " END\n";
    Queue<Card> partialDeck = Queue<Card>();
    for (int j = 0; j < 13; j++)
    {
        Card tempCard = draw();
        Card *tempCardPtr = new Card(tempCard.getFace(), tempCard.getValue(), tempCard.getFaceUp());
        partialDeck.enqueue(tempCardPtr);
    }
    DeckOfCards *temp = new DeckOfCards(partialDeck);
    return temp;
}*/













/*tempCard = queueOfDecks.front()->draw();
if (tempCard.getValue() == -1)
{
    cout << "empty";
}
cout << tempCard;
cout << "beans";
//Card some = queueOfDecks.front()->draw();
//cout << some;

DeckOfCards* tempDeckPtr2 = new DeckOfCards(true);
tempCard = tempDeckPtr2->draw();
cout << "start here" << tempCard << "end here";
for (int j = 0; j < 13; j++)
{
    tempCard = draw();
    cout << tempCard;
    tempDeckPtr2->addCard(tempCard);
}
cout << "here";
//tempDeckPtr2 = new DeckOfCards(true);
cout << queueOfDecks.getSize();
queueOfDecks.enqueue(tempDeckPtr2);
//delete tempDeckPtr2;
cout << queueOfDecks.getSize();

DeckOfCards* tempDeckPtr3 = new DeckOfCards(true);
tempCard = tempDeckPtr3->draw();
cout << "start here" << tempCard << "end here";
for (int j = 0; j < 13; j++)
{
    tempCard = draw();
    cout << tempCard;
    tempDeckPtr3->addCard(tempCard);
}
cout << "here";
//tempDeckPtr3 = new DeckOfCards(true);
cout << queueOfDecks.getSize();
queueOfDecks.enqueue(tempDeckPtr3);
//delete tempDeckPtr3;
cout << queueOfDecks.getSize();

DeckOfCards* tempDeckPtr4 = new DeckOfCards(true);
tempCard = tempDeckPtr4->draw();
cout << "start here" << tempCard << "end here";
for (int j = 0; j < 13; j++)
{
    tempCard = draw();
    cout << tempCard;
    tempDeckPtr4->addCard(tempCard);
}
cout << "here";
//tempDeckPtr4 = new DeckOfCards(true);
cout << queueOfDecks.getSize();
queueOfDecks.enqueue(tempDeckPtr4);
//delete tempDeckPtr4;
cout << queueOfDecks.getSize();

cout << "a";
DeckOfCards d = queueOfDecks.dequeue();
cout << queueOfDecks.getSize();
tempCard = queueOfDecks.front()->draw();
tempCard = queueOfDecks.front()->draw();
tempCard = queueOfDecks.front()->draw();
tempCard = queueOfDecks.front()->draw();
tempCard = queueOfDecks.front()->draw();
if (tempCard.getValue() == -1)
{
    cout << "empty";
}
cout << "start output"<< tempCard;// << "end";
tempDeckPtr = NULL;
tempDeckPtr2 = NULL;
tempDeckPtr3 = NULL;
tempDeckPtr4 = NULL;
queueOfDecks = Queue<DeckOfCards>();*/











/*
//int rand(void);
DeckOfCards tempDeck(true);
/*
for (int i = 0; i < 1000; i++)
{
    for (int i = 0; i <= rand() % 4; i++)
    {
        tempDeck = queueOfDecks.dequeue();
        queueOfDecks.enqueue(&tempDeck);
    }

    Card tempCard = queueOfDecks.front()->draw();

    for (int i = 0; i < rand() % 4; i++)
    {
        tempDeck = queueOfDecks.dequeue();
        queueOfDecks.enqueue(&tempDeck);
    }

    tempDeck = queueOfDecks.dequeue();
    tempDeck.addCard(tempCard);
    queueOfDecks.enqueue(&tempDeck);
}


for (int i = 0; i < 4; i++)
{
    tempDeck = queueOfDecks.dequeue();
    for (int j = 0; j < 13; j++)
    {
        tempCard = tempDeck.draw();
        cout << "start" << tempCard << "end";
        addCard(tempCard);
    }
}*/



Card DeckOfCards::draw()
{
    if (deck.getSize() == 0)
    {
        Card temp = Card();
        return temp;
    }
    return deck.dequeue();
}

void DeckOfCards::addCard(Card &cardToAdd)
{
    Card *cardToAdd2 = new Card(cardToAdd.getFace(), cardToAdd.getValue(), cardToAdd.getFaceUp());
    //cout << *cardToAdd2;
    deck.enqueue(cardToAdd2);
    //cardToAdd2 = NULL;
    //cout << "beep";
    cardToAdd2 = deck.front();
    //cout << *cardToAdd2 << deck.getSize();
}

void DeckOfCards::addSuit(string suit)
{
    string face;
    Card *temp;
    for (int i = 2; i <= 10; i++)
    {
        string str;
        ostringstream stream;
        stream << i;
        str = stream.str();

        face = str + "-" + suit;
        temp = new Card(face, i, false);
        deck.enqueue(temp);
    }
    face = "J-" + suit;
    temp = new Card(face, 10, false);
    deck.enqueue(temp);

    face = "Q-" + suit;
    temp = new Card(face, 10, false);
    deck.enqueue(temp);

    face = "K-" + suit;
    temp = new Card(face, 10, false);
    deck.enqueue(temp);

    face = "A-" + suit;
    temp = new Card(face, 11, false);
    deck.enqueue(temp);
}

int DeckOfCards::getSize()
{
    return deck.getSize();
}