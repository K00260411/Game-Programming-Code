#include "Boss.h"
#include "Enemy.h"
#include <vector>

int main()
{
    cout << "Calling Attack() on Boss object through pointer to Enemy:\n";
    Enemy* pBadGuy = new Boss();
    pBadGuy->Attack();

	cout << "Calling Attack() on Enemy object through pointer to Enemy:\n";
	Enemy* pEnemy = new Enemy();
	pEnemy->Attack();

	cout << "Calling Attack() on Enemy object through pointer to Enemy:\n";
	Enemy* pEnemy2 = new Enemy();
	pEnemy2->Attack();


	vector<Enemy*> vpEnemies; //created a vector of Enemy pointers
	vpEnemies.push_back(pBadGuy); //added  to the vector
	vpEnemies.push_back(pEnemy);
	vpEnemies.push_back(pEnemy2);

	vector<Enemy*>::const_iterator iter;
	cout << "Using a vector to cycle through all the Enemies \n";

	for (iter = vpEnemies.begin(); iter != vpEnemies.end(); ++iter)
	{
		(*iter)->Attack(); //whatever we call is attacking
	}

	cout << "\n\nDeleting pointer to Enemy:\n";
	delete pBadGuy;
	pBadGuy = 0;

	return 0;
}
