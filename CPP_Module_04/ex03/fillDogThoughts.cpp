#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Brain.hpp"

void	fillDogThoughts(Brain* brain)
{
	const std::string subjects[] = {
		"I", "ME", "DOG", "GOOD DOG", "HUNGRY DOG", "FAST DOG"
	};

	const std::string verbs[] = {
		"WANT", "NEED", "SMELL", "SEE", "HEAR", "LOVE", "CHASE"
	};

	const std::string objects[] = {
		"FOOD",
		"BALL",
		"HUMAN",
		"SQUIRREL",
		"CAT",
		"SOFA",
		"OUTSIDE",
		"TREATS",
		"SHOES"
	};

	const std::string emotions[] = {
		"NOW",
		"SOON",
		"FOREVER",
		"RIGHT NOW",
		"VERY MUCH",
		"PLEASE"
	};

	const int subjCount = sizeof(subjects) / sizeof(subjects[0]);
	const int verbCount = sizeof(verbs) / sizeof(verbs[0]);
	const int objCount  = sizeof(objects) / sizeof(objects[0]);
	const int emoCount  = sizeof(emotions) / sizeof(emotions[0]);

	std::string dogThoughts[100];

	std::srand(std::time(NULL));

	for (int i = 0; i < 100; ++i)
	{
		dogThoughts[i] =
			subjects[std::rand() % subjCount] + " " +
			verbs[std::rand() % verbCount] + " " +
			objects[std::rand() % objCount] + " " +
			emotions[std::rand() % emoCount];
	}
	brain->setIdeas(dogThoughts);
	// for (int i = 0; i < 100; i++) {
	// 	std::cout << brain->getRandomIdea() << std::endl;
	// }
}
