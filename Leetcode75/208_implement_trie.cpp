#include <string>
#include <iostream>

class Trie {
	private:
		Trie*	nextNodes[26] = {};
		bool	isWordEnd = false;

		Trie*	iterateDown(std::string word);
	public:
		Trie();
		
		void	insert(std::string word);
		bool	search(std::string word);
		bool	startsWith(std::string prefix);
};

Trie::Trie(){};


Trie*	Trie::iterateDown(std::string word)
{
	std::string::iterator	iterWord = word.begin();
	std::string::iterator	iterEndWord = word.end();
	Trie*					iterNode = this;
	int						indexLetter;

	while (iterWord != iterEndWord)
	{
		indexLetter = *iterWord - 'a';
		if (iterNode->nextNodes[indexLetter] == NULL)
			return NULL;
		iterNode = iterNode->nextNodes[indexLetter];
		iterWord++;
	}
	return iterNode;
}

void Trie::insert(std::string word)
{
	std::string::iterator	iterWord = word.begin();
	std::string::iterator	iterEndWord = word.end();
	Trie*					iterNode = this;
	int						indexLetter;

	while (iterWord != iterEndWord)
	{
		indexLetter = *iterWord - 'a';
		if (iterNode->nextNodes[indexLetter] == NULL)
			iterNode->nextNodes[indexLetter] = new Trie();
		iterNode = iterNode->nextNodes[indexLetter];
		iterWord++;
	}
	iterNode->isWordEnd = true;
}

bool Trie::search(std::string word)
{
	Trie*	find;

	find = iterateDown(word);
	return ((find != NULL) && find->isWordEnd);
}

bool Trie::startsWith(std::string prefix)
{
	Trie*	find;

	find = iterateDown(prefix);
	return find != NULL;
}


int	main()
{
	Trie*	solve = new Trie;

	std::string	line1 = "and";
	std::string	line2 = "ant";
	std::string	line3 = "an";

	std::cout << solve->search(line1) << std::endl;
	solve->insert(line1);
	std::cout << solve->search(line1) << std::endl;
	std::cout << solve->startsWith(line3) << std::endl;
	std::cout << solve->search(line2) << std::endl;
	solve->insert(line2);
	std::cout << solve->search(line2) << std::endl;
	return (0);
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */