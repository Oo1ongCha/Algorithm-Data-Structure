#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Card {
	char  suit;
	int n;
	string num;
	Card(char d, int n, string num) : suit(d), n(n), num(num) {};

	bool operator>  (const Card& c) const {
		if (c.suit == suit) {
			return n > c.n;
		}
		else return suit > c.suit;
	}

	bool operator<  (const Card& c) const {
		if (c.suit == suit) {
			return n < c.n;
		}
		else return suit < c.suit;//return !(*this > c);
	}
};

ostream& operator<<(ostream& out, const Card& foo) {
	return out << setw(3) << foo.suit << setw(2) << foo.num;
}

int main()
{
	srand(static_cast<unsigned>(time(NULL)));

	vector< priority_queue<Card, vector<Card>, greater<Card> > >  cards_players;
	priority_queue<Card, vector<Card>, greater<Card> > card_player;

	vector< priority_queue<Card, vector<Card>, less<Card> > >  cardsbigsmall;
	priority_queue<Card, vector<Card>, less<Card> > cardbigsmall;
	vector <Card> allcards;

	string suit = { 'C','D','H','S' };
	string number[13] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };

	int players = 4;  // 四人比撲克牌大小
	int cardno = 5;   // 每人五張牌
	int i, j, n, m;
	int cano[52];

	for (i = 0; i < 4; i++) { //全部的牌
		for (j = 0; j < 13; j++) {
			Card card(suit[i], j, number[j]);
			allcards.push_back(card);
		}
	}

	for (i = 0; i < 52; i++) cano[i] = i;
	for (i = 0; i < 52; i++) { //shuffle
		n = rand() % 52;
		int  tmp = cano[i];
		cano[i] = cano[n];
		cano[n] = tmp;
	}

	for (i = 0; i < players; i++) { //分牌
		for (j = 0; j < cardno; j++) {
			m = cano[cardno * i + j];

			card_player.push(allcards[m]);
		}
		cards_players.push_back(card_player);
		while (!card_player.empty()) card_player.pop();
	}

	for (i = 0; i < 5; i++) {
		cout << i + 1 << " :";
		for (j = 0; j < 4; j++) {
			cout << cards_players[j].top() << " ";
			cardbigsmall.push(cards_players[j].top());
			cards_players[j].pop();
		}
		cardsbigsmall.push_back(cardbigsmall);
		while (!cardbigsmall.empty()) cardbigsmall.pop();
		cout << "  --> ";
		for (j = 0; j < 4; j++) {
			cout << cardsbigsmall[i].top() << " ";
			cardsbigsmall[i].pop();
		}
		cout << endl;
	}
}
