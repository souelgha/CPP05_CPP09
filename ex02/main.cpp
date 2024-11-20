
#include <iostream>
#include<algorithm>
#include<vector>
#include<ctime>
#include<iterator>
#include<utility> // pour les paires

/*etape 1
 je fais des paires d'éléments (e.g. en doublant la longueur de mes itérateurs), 
 je trie les deux éléments entre eux. 
 A la fin de l’étape 1, 
 j'ai une liste de paires d'éléments 
  si on me donne le plus grand élément d'une paire, il faut que je puisse retourner le plus petit immédiatement

*/


std::vector<std::pair<int, int> > Createpaires(std::vector<int> &input)
{
	std::vector<std::pair<int, int> > paires;

	for(size_t i=0; i+1 < input.size(); i+=2)
	{
		if(input[i]< input[i+1])
			paires.push_back(std::make_pair(input[i], input[i+1]));
		else
			paires.push_back(std::make_pair(input[i+1], input[i]));
	}
	return paires;
}



int main()
{
	std::vector<int> input;
	srand(time(0));

	for(int i = 0; i < 10 ; i++)
		input.push_back(rand() % 100);
	std::cout<< "--------input-------\n";
	for(size_t i = 0 ; i < 10 ; i++)
		std::cout<<" " << input[i];
	std::cout<< "\n";

	std::vector<std::pair<int, int> > paires;
	paires = Createpaires(input);
	for (size_t i=0; i < paires.size(); i++)
		std::cout << "pairs: ("<< paires[i].first<< "," << paires[i].second << ") ; ";
	std::cout<< "\n";
	
	return(0);

}